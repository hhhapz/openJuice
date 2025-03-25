/**
 * @file Internet.cppm
 * @brief Module file for (experimental) standard library networking internet operations.
 *
 * This file contains the implementation of the (experimental) networking internet operations in the standard library.
 */


module;

#ifdef __GNUC__
#ifdef EXPERIMENTAL_STD
#include <experimental/internet>
#endif
#endif

#ifdef NO_RESERVED_STD
export module std.net.Internet;
#else
export module stdlib.net.Internet;
#endif

/**
 * @namespace stdlib::net
 * @brief Wrapper namespace for (experimental) standard library networking operations.
 */
export namespace stdlib::net {
    /**
     * @namespace ip
     * @brief Namespace for operations IP addresses.
     */
    namespace ip {
        #ifdef EXPERIMENTAL_STD
        using AddressV4 = std::experimental::net::ip::address_v4;
        using AddressV6 = std::experimental::net::ip::address_v6;
        using Address = std::experimental::net::ip::address;
        using NetworkV4 = std::experimental::net::ip::network_v4;
        using NetworkV6 = std::experimental::net::ip::network_v6;
        using ResolverBase = std::experimental::net::ip::resolver_base;
        using UDP = std::experimental::net::ip::udp;
        using TCP = std::experimental::net::ip::tcp;

        template<typename InternetProtocol>
        using BasicEndpoint = std::experimental::net::ip::basic_endpoint<InternetProtocol>;

        template<typename InternetProtocol>
        using BasicResolverResults = std::experimental::net::ip::basic_resolver_results<InternetProtocol>;

        using V6Only = std::experimental::net::ip::v6_only;
        #endif

        /**
         * @namespace unicast
         * @brief Namespace for operations on unicast.
         */
        namespace unicast {
            #ifdef EXPERIMENTAL_STD
            using Hops = std::experimental::net::ip::unicast::hops;
            #endif
        }

        /**
         * @namespace multicast
         * @brief Namespace for operations on multicast.
         */
        namespace multicast {
            #ifdef EXPERIMENTAL_STD
            using JoinGroup = std::experimental::net::ip::multicast::join_group;
            using LeaveGroup = std::experimental::net::ip::multicast::leave_group;
            using OutboundInterface = std::experimental::net::ip::multicast::outbound_interface;
            using Hops = std::experimental::net::ip::multicast::hops;
            using EnableLoopback = std::experimental::net::ip::multicast::enable_loopback;
            #endif
        }
    }
}
