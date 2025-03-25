/**
 * @file tomlpp.cppm
 * @brief File containing the module declaration for toml++.
 */

module;

#include <toml++/toml.hpp>

export module tomlpp;

/**
 * @namespace toml
 * @brief The toml++ namespace toml:: 
 */
export namespace toml {
    /**
     * @namespace literals
     * @brief The toml++ namespace toml::literals::
     */
    namespace literals {
        using toml::literals::operator""_toml;
        using toml::literals::operator""_tpath;
    }

    using Array = toml::array;
    using Date = toml::date;
    using DateTime = toml::date_time;

    template<typename T>
    using Inserter = toml::inserter<T>;

    using JsonFormatter = toml::json_formatter;
    using Key = toml::key;
    using Node = toml::node;

    template<typename T>
    using NodeView = toml::node_view<T>;

    using ParseError = toml::parse_error;
    using ParseResult = toml::parse_result;
    using Path = toml::path;
    using PathComponent = toml::path_component;
    using SourcePosition = toml::source_position;
    using SourceRegion = toml::source_region;
    using Table = toml::table;
    using Time = toml::time;
    using TimeOffset = toml::time_offset;
    using TomlFormatter = toml::toml_formatter;

    template<typename T>
    using Value = toml::value<T>;
    
    using YamlFormatter = toml::yaml_formatter;

    using FormatFlags = toml::format_flags;
    using NodeType = toml::node_type;
    using PathComponentType = toml::path_component_type;
    using ValueFlags = toml::value_flags;

    using ArrayIterator = toml::array_iterator;
    using ConstArrayIterator = toml::const_array_iterator;
    using ConstTableIterator = toml::const_table_iterator;
    using DefaultFormatter = toml::default_formatter;

    template<typename T>
    using InsertedTypeOf = toml::inserted_type_of<T>;

    template<typename T>
    using Optional = toml::optional<T>;

    using SourceIndex = toml::source_index;
    using SourcePathPtr = toml::source_path_ptr;
    using TableIterator = toml::table_iterator;

    using toml::at_path;
    using toml::operator""_toml;
    using toml::operator""_tpath;
    using toml::operator<<;
    using toml::parse;
    using toml::parse_file;

    template<typename T>
    constexpr bool isArray = toml::is_array<T>;

    template<typename T>
    constexpr bool isBoolean = toml::is_boolean<T>;

    template<typename T>
    constexpr bool isChronological = toml::is_chronological<T>;
    
    template<typename T>
    constexpr bool isContainer = toml::is_container<T>;

    template<typename T>
    constexpr bool isDate = toml::is_date<T>;

    template<typename T>
    constexpr bool isDateTime = toml::is_date_time<T>;

    template<typename T>
    constexpr bool isFloatingPoint = toml::is_floating_point<T>;

    template<typename T>
    constexpr bool isInteger = toml::is_integer<T>;

    template<typename T>
    constexpr bool isKey = toml::is_key<T>;

    template<typename T>
    constexpr bool isKeyOrConvertible = toml::is_key_or_convertible<T>;

    template<typename T>
    constexpr bool isNode = toml::is_node<T>;

    template<typename T>
    constexpr bool isNodeView = toml::is_node_view<T>;

    template<typename T>
    constexpr bool isNumber = toml::is_number<T>;

    template<typename T>
    constexpr bool isString = toml::is_string<T>;

    template<typename T>
    constexpr bool isTable = toml::is_table<T>;

    template<typename T>
    constexpr bool isTime = toml::is_time<T>;

    template<typename T>
    constexpr bool isValue = toml::is_value<T>;

    constexpr ValueFlags preserveSourceValueFlags = toml::preserve_source_value_flags;
}