# Taken from: https://cmake.org/Wiki/CMakeUserFindMySQL
# Edited to workt with the mysqlcppconn libraries

# - Find mysqlclient
# Find the native MySQL includes and library
#
#  MYSQL_INCLUDE_DIR - where to find mysql.h, etc.
#  MYSQL_LIBRARIES   - List of libraries when using MySQL.
#  MYSQL_FOUND       - True if MySQL found.

IF (MYSQL_INCLUDE_DIR)
    # Already in cache, be silent
    SET(MYSQL_FIND_QUIETLY TRUE)
ENDIF (MYSQL_INCLUDE_DIR)

FIND_PATH(MYSQL_INCLUDE_DIR
    mysql_connection.h
    driver.h
    exception.h
    resultset.h
    statement.h
    /usr/local/include
    /usr/include
    /usr/local/include/cppconn
    /usr/include/cppconn
)

SET(MYSQL_NAMES mysqlcppconn)
FIND_LIBRARY(MYSQL_LIBRARY
    NAMES ${MYSQL_NAMES}
    PATHS /usr/lib /usr/local/lib
)

IF (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
    SET(MYSQL_FOUND TRUE)
    SET( MYSQL_LIBRARIES ${MYSQL_LIBRARY} )
ELSE (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)
    SET(MYSQL_FOUND FALSE)
    SET( MYSQL_LIBRARIES )
ENDIF (MYSQL_INCLUDE_DIR AND MYSQL_LIBRARY)

IF (MYSQL_FOUND)
    IF (NOT MYSQL_FIND_QUIETLY)
        MESSAGE(STATUS "Found MySQL: ${MYSQL_LIBRARY}")
    ENDIF (NOT MYSQL_FIND_QUIETLY)
ELSE (MYSQL_FOUND)
    IF (MYSQL_FIND_REQUIRED)
        MESSAGE(STATUS "Looked for MySQL libraries named ${MYSQL_NAMES}.")
        MESSAGE(FATAL_ERROR "Could NOT find MySQL library")
    ENDIF (MYSQL_FIND_REQUIRED)
ENDIF (MYSQL_FOUND)

MARK_AS_ADVANCED(
    MYSQL_LIBRARY
    MYSQL_INCLUDE_DIR
)