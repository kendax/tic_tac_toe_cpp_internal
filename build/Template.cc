//this file is generated by program(drogon_ctl) automatically,don't modify it!
#include "Template.h"
#include <drogon/utils/OStringStream.h>
#include <string>
#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <list>
#include <deque>
#include <queue>
using namespace drogon;
std::string Template::genText(const DrTemplateData& Template_view_data)
{
	drogon::OStringStream Template_tmp_stream;
	std::string layoutName{""};
	Template_tmp_stream << "<!DOCTYPE html>\n";
	Template_tmp_stream << "<html>\n";
	Template_tmp_stream << "    ";
        //Fetch data from the C++ backend to be used by the template
        std::string gamestate0 = Template_view_data.get<std::string>("gamestate0");
        std::string gamestate1 = Template_view_data.get<std::string>("gamestate1");
        std::string gamestate2 = Template_view_data.get<std::string>("gamestate2");
        std::string gamestate3 = Template_view_data.get<std::string>("gamestate3");
        std::string gamestate4 = Template_view_data.get<std::string>("gamestate4");
        std::string gamestate5 = Template_view_data.get<std::string>("gamestate5");
        std::string gamestate6 = Template_view_data.get<std::string>("gamestate6");
        std::string gamestate7 = Template_view_data.get<std::string>("gamestate7");
        std::string gamestate8 = Template_view_data.get<std::string>("gamestate8");
        std::string disable = Template_view_data.get<std::string>("disable");
        std::string gamestatus = Template_view_data.get<std::string>("gamestatus");
    
	Template_tmp_stream << "<head>\n";
	Template_tmp_stream << "    <meta charset=\"UTF-8\">\n";
	Template_tmp_stream << "    <meta name=\"viewport\" content=\"width=device-width,initial-scale=1,maximum-scale=1\">\n";
	Template_tmp_stream << "    <title>TicTacToe game</title>\n";
	Template_tmp_stream << "    <style>\n";
	Template_tmp_stream << "        @import url(//fonts.googleapis.com/css?family=Roboto&display=swap);\n";
	Template_tmp_stream << "        @import url(//cdnjs.cloudflare.com/ajax/libs/normalize/8.0.1/normalize.min.css);\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        body {\n";
	Template_tmp_stream << "            padding: 0;\n";
	Template_tmp_stream << "            margin: 0;\n";
	Template_tmp_stream << "            width: 100vw;\n";
	Template_tmp_stream << "            height: 100vh;\n";
	Template_tmp_stream << "            display: flex;\n";
	Template_tmp_stream << "            justify-content: center;\n";
	Template_tmp_stream << "            align-items: center;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        body, input, button {\n";
	Template_tmp_stream << "            font-family: 'Roboto', Arial, Helvetica, sans-serif;\n";
	Template_tmp_stream << "            font-size: 12pt;\n";
	Template_tmp_stream << "            color: #333;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        input[type=text] {\n";
	Template_tmp_stream << "            border-radius: 10px;\n";
	Template_tmp_stream << "            border: 1px solid #eee;\n";
	Template_tmp_stream << "            margin: 3px 0;\n";
	Template_tmp_stream << "            width: 265px;\n";
	Template_tmp_stream << "            padding: 8px 5px;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        button {\n";
	Template_tmp_stream << "            background-color: #ff3111;\n";
	Template_tmp_stream << "            color: #FFF;\n";
	Template_tmp_stream << "            border: 0;\n";
	Template_tmp_stream << "            border-radius: 10px;\n";
	Template_tmp_stream << "            padding: 1em 2em;\n";
	Template_tmp_stream << "            cursor: pointer;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        button[disabled] {\n";
	Template_tmp_stream << "            cursor: not-allowed;\n";
	Template_tmp_stream << "            opacity: .5;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .wrapper {\n";
	Template_tmp_stream << "            display: flex;\n";
	Template_tmp_stream << "            flex-direction: column;\n";
	Template_tmp_stream << "            text-align: center;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .welcome h1,\n";
	Template_tmp_stream << "        .welcome h2 {\n";
	Template_tmp_stream << "            text-align: center;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .welcome input {\n";
	Template_tmp_stream << "            width: 100%;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .wrapper td {\n";
	Template_tmp_stream << "            text-align: center;\n";
	Template_tmp_stream << "            vertical-align: middle;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .tic-tac-toe {\n";
	Template_tmp_stream << "            margin: 3em;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .tic-tac-toe td {\n";
	Template_tmp_stream << "            border: 1px solid white;\n";
	Template_tmp_stream << "            width: 100px;\n";
	Template_tmp_stream << "            height: 100px;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .tic-tac-toe .vertical-border {\n";
	Template_tmp_stream << "            border-left-color: #eee;\n";
	Template_tmp_stream << "            border-right-color: #eee;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .tic-tac-toe .horizontal-border {\n";
	Template_tmp_stream << "            border-top-color: #eee;\n";
	Template_tmp_stream << "            border-bottom-color: #eee;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .tic-tac-toe .center-border {\n";
	Template_tmp_stream << "            border-color: #eee;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .welcome .player-name {\n";
	Template_tmp_stream << "            margin: 30px 0;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .reset-btn {\n";
	Template_tmp_stream << "            display: inline-block;\n";
	Template_tmp_stream << "            font-size: 8pt;\n";
	Template_tmp_stream << "            color: red;\n";
	Template_tmp_stream << "            margin-top: 30px;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .game-grid {\n";
	Template_tmp_stream << "            display: grid;\n";
	Template_tmp_stream << "            grid-template-columns: repeat(3, auto);\n";
	Template_tmp_stream << "            width: 310px;\n";
	Template_tmp_stream << "            margin: 15px auto;\n";
	Template_tmp_stream << "            background-color: brown;\n";
	Template_tmp_stream << "            color: rgb(4, 19, 49);\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .cells {\n";
	Template_tmp_stream << "            font-family: Arial, Helvetica, sans-serif;\n";
	Template_tmp_stream << "            width: 100px;\n";
	Template_tmp_stream << "            height: 100px;\n";
	Template_tmp_stream << "            box-shadow: 2px 2px 2px 2px rgb(20, 132, 132);\n";
	Template_tmp_stream << "            border: 2px solid rgb(20, 132, 132);\n";
	Template_tmp_stream << "            cursor: pointer;\n";
	Template_tmp_stream << "            line-height: 100px;\n";
	Template_tmp_stream << "            font-size: 60px;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .game-title {\n";
	Template_tmp_stream << "            font-size: 100px;\n";
	Template_tmp_stream << "            color: burlywood;\n";
	Template_tmp_stream << "            margin: 15px auto;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .language-implementation {\n";
	Template_tmp_stream << "            font-size: 30px;\n";
	Template_tmp_stream << "            color: burlywood;\n";
	Template_tmp_stream << "            margin: 15px auto;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .game-status {\n";
	Template_tmp_stream << "            font-size: 50px;\n";
	Template_tmp_stream << "            margin: 25px auto;\n";
	Template_tmp_stream << "            color: tomato;\n";
	Template_tmp_stream << "        }\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "        .game-restart {\n";
	Template_tmp_stream << "            background-color: rgb(251, 128, 5);\n";
	Template_tmp_stream << "            width: 200px;\n";
	Template_tmp_stream << "            height: 50px;\n";
	Template_tmp_stream << "            font-size: 25px;\n";
	Template_tmp_stream << "            color: rgb(4, 20, 24);\n";
	Template_tmp_stream << "            box-shadow: 2px 2px 2px 2px rgb(103, 1, 17);\n";
	Template_tmp_stream << "            border: 2px solid rgb(103, 1, 17);\n";
	Template_tmp_stream << "        }\n";
	Template_tmp_stream << "    </style>\n";
	Template_tmp_stream << "</head>\n";
	Template_tmp_stream << "<body>\n";
Template_tmp_stream<<"\n";
	Template_tmp_stream << "    <div class=\"wrapper\">\n";
	Template_tmp_stream << "<h1 class=\"game-title\">Tic-tac-toe</h1>\n";
	Template_tmp_stream << "<h2 class=\"language-implementation\">Program logic implemented in C++</h2>\n";
	Template_tmp_stream << "<form action=\"/postinput\" method=\"post\">\n";
	Template_tmp_stream << "    <div class=\"game-grid\">\n";
	Template_tmp_stream << "        <div data-cell-index=\"0\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate0 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate0 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" id=\"btn\" name=\"cell0\" value=\"0\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"1\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate1 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate1 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell1\" value=\"1\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"2\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate2 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate2 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell2\" value=\"2\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"3\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate3 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate3 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell3\" value=\"3\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"4\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate4 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate4 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell4\" value=\"4\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"5\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate5 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate5 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell5\" value=\"5\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"6\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate6 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate6 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell6\" value=\"6\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"7\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate7 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate7 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell7\" value=\"7\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "        <div data-cell-index=\"8\" class=\"cells\">\n";
	Template_tmp_stream << "            ";
 if (gamestate8 == "X") {
	Template_tmp_stream << "                X\n";
	Template_tmp_stream << "            ";
} else if (gamestate8 == "O") {
	Template_tmp_stream << "                O\n";
	Template_tmp_stream << "            ";
} else {
	Template_tmp_stream << "                <input type=\"radio\" name=\"cell8\" value=\"8\" ";
Template_tmp_stream<<disable;
	Template_tmp_stream << " onclick=\"document.querySelector('#play-btn').click();\"/>\n";
	Template_tmp_stream << "            ";
}
	Template_tmp_stream << "        </div>\n";
	Template_tmp_stream << "    </div>\n";
	Template_tmp_stream << "    <h3 class=\"game-status\" >";
Template_tmp_stream<<gamestatus;
	Template_tmp_stream << "</h3>\n";
	Template_tmp_stream << "    <button type=\"submit\" name=\"playButton\" id=\"play-btn\" value=\"submitted\" hidden>Play</button>\n";
	Template_tmp_stream << "    <input type=\"submit\" name=\"restartButton\" value=\"Restart Button\" class=\"game-restart\"/>\n";
	Template_tmp_stream << "</form>\n";
	Template_tmp_stream << "</div>\n";
	Template_tmp_stream << "</body>\n";
	Template_tmp_stream << "</html>\n";
if(layoutName.empty())
{
std::string ret{std::move(Template_tmp_stream.str())};
return ret;
}else
{
auto templ = DrTemplateBase::newTemplate(layoutName);
if(!templ) return "";
HttpViewData data = Template_view_data;
auto str = std::move(Template_tmp_stream.str());
if(!str.empty() && str[str.length()-1] == '\n') str.resize(str.length()-1);
data[""] = std::move(str);
return templ->genText(data);
}
}
