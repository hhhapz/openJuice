/**
 * @file FileSystem.cppm
 * @brief Module file for standard library file system operations.
 *
 * This file contains the implementation of the file system operations in the standard library.
 */

module;

#include <filesystem>

#ifdef NO_RESERVED_STD
export module std.fs.FileSystem;
#else
export module stdlib.fs.FileSystem;
#endif

/**
 * @namespace stdlib::filesystem
 * @brief Wrapper namespace for standard library file system operations.
 */
export namespace stdlib::filesystem {
    using Path = std::filesystem::path;
    using DirectoryEntry = std::filesystem::directory_entry;
    using DirectoryIterator = std::filesystem::directory_iterator;
    using RecursiveDirectoryIterator = std::filesystem::recursive_directory_iterator;
    using FileStatus = std::filesystem::file_status;
    using SpaceInfo = std::filesystem::space_info;

    using FileType = std::filesystem::file_type;
    using Perms = std::filesystem::perms;
    using PermOptions = std::filesystem::perm_options;
    using CopyOptions = std::filesystem::copy_options;
    using DirectoryOptions = std::filesystem::directory_options;
    using FileTimeType = std::filesystem::file_time_type;

    using FileSystemException = std::filesystem::filesystem_error;

    using std::filesystem::absolute;
    using std::filesystem::canonical;
    using std::filesystem::weakly_canonical;
    using std::filesystem::relative;
    using std::filesystem::proximate;
    using std::filesystem::copy;
    using std::filesystem::copy_file;
    using std::filesystem::copy_symlink;
    using std::filesystem::create_directory;
    using std::filesystem::create_directories;
    using std::filesystem::create_hard_link;
    using std::filesystem::create_symlink;
    using std::filesystem::create_directory_symlink;
    using std::filesystem::current_path;
    using std::filesystem::exists;
    using std::filesystem::equivalent;
    using std::filesystem::file_size;
    using std::filesystem::hard_link_count;
    using std::filesystem::last_write_time;
    using std::filesystem::permissions;
    using std::filesystem::read_symlink;
    using std::filesystem::remove;
    using std::filesystem::remove_all;
    using std::filesystem::rename;
    using std::filesystem::resize_file;
    using std::filesystem::space;
    using std::filesystem::status;
    using std::filesystem::symlink_status;
    using std::filesystem::temp_directory_path;

    using std::filesystem::is_block_file;
    using std::filesystem::is_character_file;
    using std::filesystem::is_directory;
    using std::filesystem::is_empty;
    using std::filesystem::is_fifo;
    using std::filesystem::is_other;
    using std::filesystem::is_regular_file;
    using std::filesystem::is_socket;
    using std::filesystem::is_symlink;
    using std::filesystem::status_known;

    using std::hash;
    using std::swap;
}
