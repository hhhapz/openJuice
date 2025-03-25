/**
 * @file Chrono.cppm
 * @brief Module file for standard library time operations.
 *
 * This file contains the implementation of the time operations in the standard library.
 */

module;

#include <chrono>

#ifdef NO_RESERVED_STD
export module std.time.Chrono;
#else
export module stdlib.time.Chrono;
#endif

/**
 * @namespace stdlib::time
 * @brief Wrapper namespace for standard library time operations.
 */
export namespace stdlib::time {
    template<typename Rep>
    using Duration = std::chrono::duration<Rep>;

    template<typename Rep>
    using TreatAsFloatingPoint = std::chrono::treat_as_floating_point<Rep>;

    template<typename Rep>
    using DurationValues = std::chrono::duration_values<Rep>;

    template<typename Duration>
    using TimePoint = std::chrono::time_point<std::chrono::system_clock, Duration>;

    template<typename Dest, typename Source>
    using ClockTimeConversion = std::chrono::clock_time_conversion<Dest, Source>;

    template<typename T>
    using IsClock = std::chrono::is_clock<T>;

    using SystemClock = std::chrono::system_clock;
    using SteadyClock = std::chrono::steady_clock;
    using HighResolutionClock = std::chrono::high_resolution_clock;
    using UTCClock = std::chrono::utc_clock;
    using TAIClock = std::chrono::tai_clock;
    using GPSClock = std::chrono::gps_clock;
    using FileClock = std::chrono::file_clock;
    using Local = std::chrono::local_t;

    using Day = std::chrono::day;
    using Month = std::chrono::month;
    using Year = std::chrono::year;
    using Weekday = std::chrono::weekday;
    using MonthDay = std::chrono::month_day;
    using YearMonth = std::chrono::year_month;
    using YearMonthDay = std::chrono::year_month_day;

    using TZDB = std::chrono::tzdb;
    using TZDBList = std::chrono::tzdb_list;
    using TimeZone = std::chrono::time_zone;
    using SysInfo = std::chrono::sys_info;
    using LocalInfo = std::chrono::local_info;

    using LeapSecond = std::chrono::leap_second;
    using LeapSecondInfo = std::chrono::leap_second_info;

    using AmbiguousLocalTimeException = std::chrono::ambiguous_local_time;
    using NonexistentLocalTimeException = std::chrono::nonexistent_local_time;

    using std::chrono::duration_cast;
    using std::chrono::time_point_cast;

    using std::chrono::get_tzdb;
    using std::chrono::get_tzdb_list;
    using std::chrono::reload_tzdb;
    using std::chrono::remote_version;
    using std::chrono::locate_zone;

    using std::chrono::get_leap_second_info;

    using std::hash;

    /**
     * @brief chrono
     * @brief Wrapper namespace for standard library chronological operations
     */
    namespace chrono {
        using LastSpec = std::chrono::last_spec;
        using WeekdayIndexed = std::chrono::weekday_indexed;
        using WeekdayLast = std::chrono::weekday_last;
        using MonthDayLast = std::chrono::month_day_last;
        using MonthWeekday = std::chrono::month_weekday;
        using MonthWeekdayLast = std::chrono::month_weekday_last;
        using YearMonthDayLast = std::chrono::year_month_day_last;
        using YearMonthWeekday = std::chrono::year_month_weekday;
        using YearMonthWeekdayLast = std::chrono::year_month_weekday_last;
        
        using Choose = std::chrono::choose;
    }

    /**
     * @brief fmt
     * @brief Wrapper namespace for standard library time formatting operations
     */
    namespace fmt {
        using std::chrono::is_am;
        using std::chrono::is_pm;
        using std::chrono::make12;
        using std::chrono::make24;

        template<typename _Duration>
        using HHMMSS = std::chrono::hh_mm_ss<_Duration>;

        using std::chrono::from_stream;
        using std::chrono::parse;
    }

    /**
     * @brief temporal
     * @brief Wrapper namespace for standard library time temporal unit operations
     */
    namespace temporal {
        using Nanoseconds = std::chrono::nanoseconds;
        using Microseconds = std::chrono::microseconds;
        using Milliseconds = std::chrono::milliseconds;
        using Seconds = std::chrono::seconds;
        using Minutes = std::chrono::minutes;
        using Hours = std::chrono::hours;
        using Days = std::chrono::days;
        using Weeks = std::chrono::weeks;
        using Months = std::chrono::months;
        using Years = std::chrono::years;
    }

    /**
     * @brief fmt
     * @brief Wrapper namespace for standard library time zone operations
     */
    namespace zone {
        template<typename _Duration>
        using ZonedTraits = std::chrono::zoned_traits<_Duration>;
    
        template<typename _Duration>
        using ZonedTime = std::chrono::zoned_time<_Duration>;
    
        using TimeZoneLink = std::chrono::time_zone_link;
    }
}
