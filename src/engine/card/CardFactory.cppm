/**
 * @file CardFactory.cppm
 * @brief Definition of the CardFactory template interface.
 *
 * This file contains the definition of the CardFactory template interface, which is used to create Card objects.
 */

export module engine.card.CardFactory;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
#else
import stdlib.core;
import stdlib.mem;
#endif
 
using stdlib::mem::SharedPtr;
 
/**
 * @interface CardFactory
 * @brief Template interface for creating Card objects.
 * 
 * The CardFactory interface is a template interface that provides an interface for creating Card objects.
 * @tparam T The type of Card to create.
 */
export template<typename T>
class CardFactory {
protected:
    /**
     * @brief Protected default constructor to prevent direct instantiation.
     */
    CardFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    CardFactory(const CardFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    CardFactory& operator=(const CardFactory&) = delete;
public:
    /**
     * @brief Pure virtual function to create a Card object.
     * @param id The ID of the Card to create.
     * @return SharedPtr<T> Shared pointer to the created Card object.
     */
    virtual SharedPtr<T> create(u8 id) const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~CardFactory() = default;
};