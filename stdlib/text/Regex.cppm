/**
 * @file Regex.cppm
 * @brief Module file for standard library regular expression operations.
 *
 * This file contains the implementation of the regular expression operations in the standard library.
 */

module;

#include <regex>

#ifdef NO_RESERVED_STD
export module std.text.Regex;
#else
export module stdlib.text.Regex;
#endif

/**
 * @namespace stdlib::text
 * @brief Wrapper namespace for standard library text operations.
 */
export namespace stdlib::text {
    template<typename T>
    using BasicRegex = std::basic_regex<T>;

    using Regex = std::regex;
    using WRegex = std::wregex;

    template<typename T>
    using SubMatch = std::sub_match<T>;

    using CSubMatch = std::csub_match;
    using WCSubMatch = std::wcsub_match;
    using SSubMatch = std::ssub_match;
    using WSSubMatch = std::wssub_match;

    template<typename BidirIt, typename Alloc>
    using MatchResults = std::match_results<BidirIt, Alloc>;

    using CMatch = std::cmatch;
    using WCMatch = std::wcmatch;
    using SMatch = std::smatch;
    using WSMatch = std::wsmatch;

    /**
     * @namespace pmr
     * @brief Namespace for operations on polymorphic memory resources.
     */
    namespace pmr {
        using CMatch = std::pmr::cmatch;
        using WCMatch = std::pmr::wcmatch;
        using SMatch = std::pmr::smatch;
        using WSMatch = std::pmr::wsmatch;
    }

    template<typename T>
    using RegexIterator = std::regex_iterator<T>;

    using CRegexIterator = std::cregex_iterator;
    using WCRegexIterator = std::wcregex_iterator;
    using SRegexIterator = std::sregex_iterator;
    using WSRegexIterator = std::wsregex_iterator;

    template<typename T>
    using RegexTokenIterator = std::regex_token_iterator<T>;

    using CRegexTokenIterator = std::cregex_token_iterator;
    using WCRegexTokenIterator = std::wcregex_token_iterator;
    using SRegexTokenIterator = std::sregex_token_iterator;
    using WSRegexTokenIterator = std::wsregex_token_iterator;

    template<typename T>
    using RegexTraits = std::regex_traits<T>;

    using SyntaxOptionType = std::regex_constants::syntax_option_type;
    using MatchFlagType = std::regex_constants::match_flag_type;
    using ErrorType = std::regex_constants::error_type;

    using RegexException = std::regex_error;

    using std::regex_match;
    using std::regex_search;
    using std::regex_replace;

    using std::swap;

    using std::begin;
    using std::cbegin;
    using std::end;
    using std::cend;
    using std::rbegin;
    using std::crbegin;
    using std::rend;
    using std::crend;
    using std::size;
    using std::ssize;
    using std::empty;
    using std::data;

    using std::operator==;
    using std::operator<=>;
    using std::operator<<;
}
