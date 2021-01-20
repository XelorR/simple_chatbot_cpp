#include <string>    // for getline function and string type
#include <iostream>  // for cin and cout
#include <algorithm> // for transform function
#include <map>       // for map function
#include <regex>     // for regular expressions

using namespace std;

void bot_say(string text)
{
    cout << "[BOT]  << " << text << endl;
}

map<string, string> knowledge = {
    {"hello", "Hey, hooman!"},
    {"how are you", "Not too bad for a robot!"},
    {"what is your name", "My creator gave me name ChatBot"},
    {"whats up", "Answering stupid questions"},
    {"what are you up to", "Answering stupid questions"},
};

string exit_phrases[] = {"exit", "bye", "have a nice day", "have a good day", "fuck you"};

bool is_exit(string text)
{
    for (auto phrase : exit_phrases)
    {
        regex expression = regex(".*" + phrase + ".*");
        if (regex_match(text, expression))
        {
            bot_say("Ok, bye");
            return true;
        }
    }
    return false;
}

void bot_answer(string question)
{
    bool answer_found = false;
    for (auto entry : knowledge)
    {
        // entry.first - question
        // entry.second - answer
        regex expression = regex(".*" + entry.first + ".*");
        if (regex_match(question, expression))
        {
            // answer
            bot_say(entry.second);
            answer_found = true;
        }
    }
    if (!answer_found)
    {
        bot_say("Don't understand your question");
    }
}

string to_lower(string text)
{
    transform(text.begin(), text.end(), text.begin(), ::tolower);
    return text;
}

string user_question()
{
    string question;
    cout << "[USER] >> ";
    getline(cin, question);
    question = to_lower(question);
    return question;
}

int main()
{

    cout << "Hello and welcome to our chatbot" << endl
         << "please type your questions below\n"
         << endl;

    string question;

    // cout << "\nYour question is: " << question << endl;

    while (!is_exit(question))
    {
        question = user_question();
        bot_answer(question);
    }

    return 0;
}
