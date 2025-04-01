/**
 * @file UnitFactory.cppm
 * @brief Definition of the UnitFactory template interface.
 *
 * This file contains the definition of the UnitFactory template interface, which is used to create Unit objects.
 */

export module engine.unit.UnitFactory;

#ifdef NO_RESERVED_STD
import std.core;
import std.mem;
#else
import stdlib.core;
import stdlib.mem;
#endif

using stdlib::mem::SharedPtr;

/**
 * @interface UnitFactory
 * @brief Template interface for creating Unit objects.
 * 
 * The UnitFactory interface is a template interface that provides an interface for creating Unit objects.
 * @tparam T The type of Unit to create.
 */
export template<typename T>
class UnitFactory {
protected:
    /**
     * @brief Protected default constructor to prevent direct instantiation.
     */
    UnitFactory() = default;

    /**
     * @brief Deleted copy constructor to prevent copying.
     */
    UnitFactory(const UnitFactory&) = delete;

    /**
     * @brief Deleted copy assignment operator to prevent copying.
     */
    UnitFactory& operator=(const UnitFactory&) = delete;
public:
    /**
     * @brief Pure virtual function to create a Unit object.
     * @param id The ID of the Unit to create.
     * @return SharedPtr<T> Shared pointer to the created Unit object.
     */
    virtual SharedPtr<T> create(u8 id) const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~UnitFactory() = default;
};