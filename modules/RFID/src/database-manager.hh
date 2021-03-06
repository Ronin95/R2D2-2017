/**
 * \file      database-manager.hh
 * \brief     Class for executing query on a RFID database
 * \author    Jeremy Ruizenaar
 * \copyright Copyright (c) 2017, The R2D2 Team
 * \license   See LICENSE
 */
#pragma once

#include "mysql.hh"

class DatabaseManager {
private:
    MySql connection;

public:
    /**
     * \brief Connects to a mysql server
     *
     *
     * Typical usage:
     * \code
     *     connectTo("tcp://someip:3306", "username", "password");
     * \endcode
     *
     * \param [in] url The url of the server
     * \param [in] username The username used to log in
     * \param [in] password The password used to log in
     *
     * \returns true on success.
     */
    void connectTo(const std::string &ip, const std::string &username, const std::string &password);

    /**
     * \brief Selects a database
     *
     * Typical usage:
     * \code
     *     selectDatabase("database");
     * \endcode
     *
     * \param [in] string database
     * \returns true on success.
     */
    void selectDatabase(const std::string &database);

    /**
     * \brief returns a string with al card id's
     *
     * Typical usage:
     * \code
     *     getAllCardIdFromDatabase();
     * \endcode
     *
     * \returns string with all card id's.
     */
    std::string getAllCardIdFromDatabase();

    /**
     * \brief checks if a card_id is authorized
     *
     * Typical usage:
     * \code
     *     getCardAuthorisationFromDatabase("cardId");
     * \endcode
     *
     * \returns true is authorized
     */
    bool getCardAuthorisationFromDatabase(const std::string &cardId);

    /**
     * \brief set the authorisation of a card in the database
     *
     * Typical usage:
     * \code
     *     setCardAuthorisationInDatabase(true, "cardId");
     * \endcode
     * \param [in] string cardId
     * \returns card is authorized or unauthorized
     */
    void setCardAuthorisationInDatabase(const bool &status, const std::string &cardId);

    /**
     * \brief check if a card is already in the database
     *
     * Typical usage:
     * \code
     *     isCardInDatabase("cardId");
     * \endcode
     * \param [in] bool status
     * \param [in] string cardId
     * \returns returns true if cardId is in th database
     */
    bool isCardInDatabase(const std::string &cardId);

    /**
     * \brief adds a card to the database
     *
     * Typical usage:
     * \code
     *     addCardToDatabase("cardId");
     * \endcode
     * \param [in] string cardId
     * \returns returns true if cardId is added to the database
     */
    bool addCardToDatabase(const std::string &cardId);

    /**
     * \brief executes a query with no result
     *
     * Typical usage:
     * \code
     *     executeQueryNoResult("query");
     * \endcode
     * \param [in] string query
     *
     */
    void executeQueryNoResult(const std::string &query);

    /**
     * \brief executes a query with  result
     *
     * Typical usage:
     * \code
     *     executeQuery("query");
     * \endcode
     * \param [in] string query
     *
     */
    void executeQuery(const std::string &query);

    /**
     * \brief get the full result set from the connection
     *
     * Typical usage:
     * \code
     *     getFullResultSet();
     * \endcode
     *
     * \return std::unique_ptr<sql::ResultSet> &
     *
     */
    std::unique_ptr<sql::ResultSet> getFullResultSet();
};
