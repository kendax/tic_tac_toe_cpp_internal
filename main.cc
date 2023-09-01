#include <drogon/drogon.h>
#include <chrono>
#include <string>
using namespace drogon;
using namespace std;
using namespace std::chrono_literals;

int main()
{
    //Handle displaying of game data in the HTML template
    app().registerHandler(
        "/",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {

        /*Get the session variable holding the value for the submit button and store it in a variable
        for use in checking if the game has started */
        std::string playbutton = req->getSession()->get<std::string>("playButton");
        // Display the first player's turn
        if (playbutton == "") {
            std::string value = "X";
            req->session()->insert("currentplayer",value);
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            std::string subCurrPlayerDuringGame = "It's " + currentPlayer + "'s turn";
            req->session()->insert("subCurrentPlayer", subCurrPlayerDuringGame);
            req->session()->insert("gamestatus", subCurrPlayerDuringGame);
        }
        
        //Get session variables and store each of them separate variables
        std::string gameState0 = req->getSession()->get<std::string>("gamestate0");
        std::string gameState1 = req->getSession()->get<std::string>("gamestate1");
        std::string gameState2 = req->getSession()->get<std::string>("gamestate2");
        std::string gameState3 = req->getSession()->get<std::string>("gamestate3");
        std::string gameState4 = req->getSession()->get<std::string>("gamestate4");
        std::string gameState5 = req->getSession()->get<std::string>("gamestate5");
        std::string gameState6 = req->getSession()->get<std::string>("gamestate6");
        std::string gameState7 = req->getSession()->get<std::string>("gamestate7");
        std::string gameState8 = req->getSession()->get<std::string>("gamestate8");
        std::string disable = req->getSession()->get<std::string>("disable");
        std::string gameStatus = req->getSession()->get<std::string>("gamestatus");
        std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
        std::string subCurrPlayerDuringGame = req->getSession()->get<std::string>("subCurrentPlayer");
        
        /*Create a dataset called 'data' using the class 'HttpViewData' and insert into it all 
        the data that will be displayed in the template */
        HttpViewData data;
        data.insert("gamestate0", gameState0);
        data.insert("gamestate1", gameState1);
        data.insert("gamestate2", gameState2);
        data.insert("gamestate3", gameState3);
        data.insert("gamestate4", gameState4);
        data.insert("gamestate5", gameState5);
        data.insert("gamestate6", gameState6);
        data.insert("gamestate7", gameState7);
        data.insert("gamestate8", gameState8);
        data.insert("disable", disable);
        data.insert("gamestatus", gameStatus);
        
        //Go to the template file along with the dataset 'data'
        auto resp = HttpResponse::newHttpViewResponse("/Template.csp", data);
        callback(resp);

        },
        {Get}); //Using GET method for this function

    //Handle validation of the game for a win, draw or continued play
    app().registerHandler(
        "/validateresult",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
        
        //Get session variables and store each of them separate variables  
        std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
        std::string gameState0 = req->getSession()->get<std::string>("gamestate0");
        std::string gameState1 = req->getSession()->get<std::string>("gamestate1");
        std::string gameState2 = req->getSession()->get<std::string>("gamestate2");
        std::string gameState3 = req->getSession()->get<std::string>("gamestate3");
        std::string gameState4 = req->getSession()->get<std::string>("gamestate4");
        std::string gameState5 = req->getSession()->get<std::string>("gamestate5");
        std::string gameState6 = req->getSession()->get<std::string>("gamestate6");
        std::string gameState7 = req->getSession()->get<std::string>("gamestate7");
        std::string gameState8 = req->getSession()->get<std::string>("gamestate8");
        std::string gameStatus = req->getSession()->get<std::string>("gamestatus");


        //Validate the game's state after a player has played for a win, draw or if the game continues
        if ((gameState0 == gameState1 && gameState1 == gameState2 && gameState2 == "X") ||
            (gameState0 == gameState4 && gameState4 == gameState8 && gameState8 == "X") ||
            (gameState0 == gameState3 && gameState3 == gameState6 && gameState6 == "X") ||
            (gameState1 == gameState4 && gameState4 == gameState7 && gameState7 == "X") ||
            (gameState2 == gameState4 && gameState4 == gameState6 && gameState6 == "X") ||
            (gameState2 == gameState5 && gameState5 == gameState8 && gameState8 == "X") ||
            (gameState3 == gameState4 && gameState4 == gameState5 && gameState5 == "X") ||
            (gameState6 == gameState7 && gameState7 == gameState8 && gameState8 == "X")) {
            req->session()->erase("gamestatus");

            std::string value = "Player X has won!";
            req->session()->insert("gamestatus", value);
        
            std::string disabledValue = "disabled";
            req->session()->insert("disable", disabledValue);
            auto resp = HttpResponse::newRedirectionResponse("/");
            callback(resp);
        } else if ((gameState0 == gameState1 && gameState1 == gameState2 && gameState2 == "O") ||
            (gameState0 == gameState4 && gameState4 == gameState8 && gameState8 == "O") ||
            (gameState0 == gameState3 && gameState3 == gameState6 && gameState6 == "O") ||
            (gameState1 == gameState4 && gameState4 == gameState7 && gameState7 == "O") ||
            (gameState2 == gameState4 && gameState4 == gameState6 && gameState6 == "O") ||
            (gameState2 == gameState5 && gameState5 == gameState8 && gameState8 == "O") ||
            (gameState3 == gameState4 && gameState4 == gameState5 && gameState5 == "O") ||
            (gameState6 == gameState7 && gameState7 == gameState8 && gameState8 == "O")) {
            req->session()->erase("gamestatus");
            std::string value = "Player O has won!";
            req->session()->insert("gamestatus", value);
            std::string disabledValue = "disabled";
            req->session()->insert("disable", disabledValue);
            auto resp = HttpResponse::newRedirectionResponse("/");
            callback(resp);
        } else if (gameState0 != "" && gameState1 != "" && gameState2 != "" && gameState3 != "" && gameState4 != "" && gameState5 != "" && gameState6 != "" && gameState7 != "" && gameState8 != "") {
            req->session()->erase("gamestatus");
            std::string value = "Game ended in a draw!";
            req->session()->insert("gamestatus", value);
            auto resp = HttpResponse::newRedirectionResponse("/");
            callback(resp);
        } else {
            if (currentPlayer == "X") {
                req->session()->erase("currentplayer");
                std::string value = "O";
                req->session()->insert("currentplayer", value);
            } else {
                req->session()->erase("currentplayer");
                std::string value = "X";
                req->session()->insert("currentplayer", value);
            }
            req->session()->erase("gamestatus");
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            std::string subCurrPlayerDuringGame = "It's " + currentPlayer + "'s turn";
            req->session()->insert("gamestatus", subCurrPlayerDuringGame);
            auto resp = HttpResponse::newRedirectionResponse("/");
            callback(resp);
        }
        },
        {Get}); //Using GET method for this function
    
    //Receive input from the game's form and store it in session variables
    app().registerHandler(
        "/postinput",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
        
        //Get the values from the game's form and store them in variables
        std::string playbutton = req->getParameter("playButton");
        std::string restartbutton = req->getParameter("restartButton");
        std::string cell0 = req->getParameter("cell0");
        std::string cell1 = req->getParameter("cell1");
        std::string cell2 = req->getParameter("cell2");
        std::string cell3 = req->getParameter("cell3");
        std::string cell4 = req->getParameter("cell4");
        std::string cell5 = req->getParameter("cell5");
        std::string cell6 = req->getParameter("cell6");
        std::string cell7 = req->getParameter("cell7");
        std::string cell8 = req->getParameter("cell8");

        //Insert the form values for the submit button and restart button into session variables
        req->session()->insert("playButton", playbutton);
        req->session()->insert("restartButton", restartbutton);

        //Check if the restart button has been clicked and if so redirect the program execution to the restart function
        if (restartbutton != "") {
        auto resp = HttpResponse::newRedirectionResponse("/restart");
        callback(resp);
        }

        /*Store the player's value for the corresponding clicked box, each in a separate session variable
        and then redirect to the validateresult function */
        if (cell0 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate0", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
            
        }
        if (cell1 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate1", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell2 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate2", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell3 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate3", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell4 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate4", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell5 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate5", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell6 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate6", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell7 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate7", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        if (cell8 != "") {
            std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
            req->session()->insert("gamestate8", currentPlayer);
            auto resp = HttpResponse::newRedirectionResponse("/validateresult");
            callback(resp);
        }
        },
        {Post}); //Using POST method for this function

    //Function for restarting the game
    app().registerHandler(
        "/restart",
        [](const HttpRequestPtr &req,
           std::function<void(const HttpResponsePtr &)> &&callback) {
            
        //Erase the game's session variables so as to start the game afresh
        req->session()->erase("currentplayer");
        req->session()->erase("gamestate0");
        req->session()->erase("gamestate1");
        req->session()->erase("gamestate2");
        req->session()->erase("gamestate3");
        req->session()->erase("gamestate4");
        req->session()->erase("gamestate5");
        req->session()->erase("gamestate6");
        req->session()->erase("gamestate7");
        req->session()->erase("gamestate8");
        req->session()->erase("gamestatus");
        req->session()->erase("disable");

        //Start new session variables for the game to start afresh with the displaying of the first player's turn
        std::string value = "X";
        req->session()->insert("currentplayer", value);
        std::string currentPlayer = req->getSession()->get<std::string>("currentplayer");
        std::string subCurrentPlayer = req->getSession()->get<std::string>("subCurrentPlayer");
        req->session()->insert("gamestatus", subCurrentPlayer);

        //Redirect to the root function
        auto resp = HttpResponse::newRedirectionResponse("/");
        callback(resp);
        },
        {Get}); //Using GET method for this function

    LOG_INFO << "Server running on 127.0.0.1:8848"; //Display in the terminal the program's address and port while running

    //Set HTTP listener address and port and run the HTTP framework
    app()
        // All sessions are stored for 24 Hours
        .enableSession(24h)
        .addListener("0.0.0.0", 8080)
        .run();
        return 0;
}