/**
 * @file KeyQueryable.cppm
 * @brief Definition of the KeyQueryable marker interface.
 *
 * This file contains the definition of the KeyQueryable marker interface, which denotes that a class queries a key from the TextManager class.
 */

export module engine.utility.Interfaces:KeyQueryable;

/**
 * @interface KeyQueryable
 * @brief Marker interface for creating KeyQueryable objects.
 * 
 * The FinalOnly marker interface is used to denote that a class will query some key from the TextManager class.
 */
export class KeyQueryable {
protected:
    /**
     * @brief Protected default constructor to prevent direct instantiation.
     */
    KeyQueryable() = default;
public:
    /**
     * @brief Virtual destructor
     */
    virtual ~KeyQueryable() = default;
};