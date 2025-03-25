/**
 * @file EntityComponentSystem.cppm
 * @brief Module file for the entity component system.
 *
 * This file contains the implementation of the entity component system.
 */

module;

#include <typeinfo>

export module engine.game.EntityComponentSystem;

#ifdef NO_RESERVED_STD
import std.core;
import std.collections;
import std.mem;
import std.util;
#else
import stdlib.core;
import stdlib.collections;
import stdlib.mem;
import stdlib.util;
#endif

using namespace collections;
using mem::SharedPtr, mem::UniquePtr;

export using EntityID = u32;

/**
 * @namespace ecs
 * @brief Namespace for entity component system operations.
 */
export namespace ecs {
    /**
     * @interface Component
     * @brief Class for a component in the ECS system.
     */
    class Component {
    public:
        virtual ~Component() = default;
    };

    /**
     * @class ComponentManager
     * @brief Manager class for all components in the ECS system.
     */
    class ComponentManager {
    private:
        UnorderedMap<String, UnorderedMap<EntityID, SharedPtr<Component>>> components; ///< A map storing components of the ECS
    public:
        /**
         * @brief Registers a component type into the component manager.
         * 
         * @tparam T 
         */
        template<typename T>
        void registerComponent() {
            String typeName = typeid(T).name();
            components[typeName] = {};
        }

        /**
         * @brief Adds a component to the entity
         * 
         * @tparam T 
         * @tparam Args 
         * @param args 
         * @return SharedPtr<T> 
         */
        template<typename T, typename... Args>
        SharedPtr<T> addComponent(EntityID entity, Args&&... args) {
            String typeName = typeid(T).name();
            SharedPtr<T> component = mem::make_shared<T>(util::forward<Args>(args)...);
            components[typeName][entity] = component;
            return mem::static_pointer_cast<T>(component);
        }

        /**
         * @brief Get the Component object
         * 
         * @tparam T 
         * @param entity 
         * @return SharedPtr<T> 
         */
        template<typename T>
        SharedPtr<T> getComponent(EntityID entity) {
            String typeName = typeid(T).name();
            UnorderedMap<EntityID, SharedPtr<Component>>& componentMap = components[typeName];
            auto it = componentMap.find(entity);
            if (it != componentMap.end())
                return mem::static_pointer_cast<T>(it->second);
            return nullptr;
        }

        /**
         * @brief 
         * 
         * @tparam T 
         * @param entity 
         */
        template<typename T>
        void removeComponent(EntityID entity) {
            String typeName = typeid(T).name();
            components[typeName].erase(entity);
        }
    };

    /**
     * @class EntityManager
     * @brief Class for managing entities
     */
    class EntityManager {
    private:
        EntityID nextID = 0; ///<
        Vector<EntityID> availableIDs; ///<
    public:
        /**
         * @brief Create a Entity object
         * 
         * @return EntityID 
         */
        EntityID createEntity() {
            if (!availableIDs.empty()) {
                EntityID id = availableIDs.back();
                availableIDs.pop_back();
                return id;
            }
            return nextID++;
        }

        /**
         * @brief 
         * 
         * @param entity 
         */
        void destroyEntity(EntityID entity) {
            availableIDs.push_back(entity);
        }
    };

    /**
     * @interface System
     * @brief Interface for a system in the ECS system
     */
    class System {
    public:
        /**
         * @brief Destroy the System object
         */
        virtual ~System() = default;
        
        /**
         * @brief 
         * 
         * @param deltaTime 
         */
        virtual void update(float deltaTime) = 0;
    };

    /**
     * @class Coordinator
     * @brief Class for coordinating components and systems
     */
    class Coordinator {
    private:
        UniquePtr<ComponentManager> componentManager;
        UniquePtr<EntityManager> entityManager;
        Vector<SharedPtr<System>> systems;
    public:
        /**
         * @brief Construct a new Coordinator object
         */
        Coordinator(): 
            componentManager{mem::make_unique<ComponentManager>()},
            entityManager{mem::make_unique<EntityManager>()} {}

        Coordinator(const Coordinator&) = delete;
        Coordinator& operator=(const Coordinator&) = delete;
        Coordinator(Coordinator&&) = delete;
        Coordinator& operator=(Coordinator&&) = delete;

        /**
         * @brief Get the Instance object
         * 
         * @return SharedPtr<Coordinator> 
         */
        static SharedPtr<Coordinator> getInstance() {
            static SharedPtr<Coordinator> instance = mem::make_shared<Coordinator>();
            return instance;
        }

        /**
         * @brief Create a Entity object
         * 
         * @return EntityID 
         */
        EntityID createEntity() {
            return entityManager->createEntity();
        }

        /**
         * @brief 
         * 
         * @param entity 
         */
        void destroyEntity(EntityID entity) {
            entityManager->destroyEntity(entity);
        }

        /**
         * @brief 
         * 
         * @tparam T 
         */
        template<typename T>
        void registerComponent() {
            componentManager->registerComponent<T>();
        }

        /**
         * @brief 
         * 
         * @tparam T 
         * @tparam Args 
         * @param entity 
         * @param args 
         * @return SharedPtr<T> 
         */
        template<typename T, typename... Args>
        SharedPtr<T> addComponent(EntityID entity, Args&&... args) {
            return componentManager->addComponent<T>(entity, util::forward<Args>(args)...);
        }

        /**
         * @brief Get the Component object
         * 
         * @tparam T 
         * @param entity 
         * @return SharedPtr<T> 
         */
        template<typename T>
        SharedPtr<T> getComponent(EntityID entity) {
            return componentManager->getComponent<T>(entity);
        }

        /**
         * @brief 
         * 
         * @tparam T 
         * @param entity 
         */
        template<typename T>
        void removeComponent(EntityID entity) {
            componentManager->removeComponent<T>(entity);
        }

        /**
         * @brief 
         * 
         * @tparam T 
         * @tparam Args 
         * @param args 
         * @return SharedPtr<T> 
         */
        template<typename T, typename... Args>
        SharedPtr<T> registerSystem(Args&&... args) {
            SharedPtr<T> system = mem::make_shared<T>(util::forward<Args>(args)...);
            systems.push_back(system);
            return system;
        }

        void update(float deltaTime) {
            for (usize i = 0; i < systems.size(); ++i) {
                #ifndef NDEBUG
                systems.at(i)->update(deltaTime);
                #else
                systems[i]->update(deltaTime);
                #endif
            }
        }
    };
}