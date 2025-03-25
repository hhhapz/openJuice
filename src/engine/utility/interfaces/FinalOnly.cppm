/**
 * @file FinalOnly.cppm
 * @brief Definition of the FinalOnly marker interface.
 *
 * This file contains the definition of the FinalOnly marker interface, which denotes that only final classes should be concrete.
 */

export module engine.utility.Interfaces:FinalOnly;

/**
 * @interface FinalOnly
 * @brief Marker interface for creating FinalOnly objects.
 * 
 * The FinalOnly marker interface is used to denote that only final classes should be concrete. Final classes should implement the method noop() as a private method with an empty body.
 */
export class FinalOnly {
    private:
    /**
     * @brief No-operation function, should only be implemented by final classes.
     */
    virtual void noop() const = 0;
protected:
    /**
     * @brief Protected default constructor to prevent direct instantiation.
     */
    FinalOnly() = default;
};