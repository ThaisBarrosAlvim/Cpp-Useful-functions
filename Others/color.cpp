std::string color(int color)
{
    //init REF:https://stackoverflow.com/questions/4053837/colorizing-text-in-the-console-with-c
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
    //end REF.
    return "";
}
