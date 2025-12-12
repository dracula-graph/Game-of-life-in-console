#include "consoleStyle.h"
// эта дает цвет тексту и фону
std::string colorize(const std::string& text, int color, int bgColor) {
    std::string textColor;
    std::string backgroundColor;

    //чтобы не выдовал ошибку если больше диопазона
    while (color > 7) {
        color -= 7;
    }
    while (bgColor > 7) {
        bgColor -= 7;
    }
    // Цвет текста
    switch (color) {
        case 0: textColor = "\033[37m"; break; // белый
        case 1: textColor = "\033[31m"; break; // красный
        case 2: textColor = "\033[33m"; break; // жёлтый
        case 3: textColor = "\033[32m"; break; // зелёный
        case 4: textColor = "\033[36m"; break; // циан
        case 5: textColor = "\033[34m"; break; // синий
        case 6: textColor = "\033[35m"; break; // магента
        case 7: textColor = "\033[30m"; break; // черный
    }
    // Цвет фона
    switch (bgColor) {
        case 0: backgroundColor = "\033[47m"; break; // белый
        case 1: backgroundColor = "\033[41m"; break; // красный
        case 2: backgroundColor = "\033[43m"; break; // жёлтый
        case 3: backgroundColor = "\033[42m"; break; // зелёный
        case 4: backgroundColor = "\033[46m"; break; // циан
        case 5: backgroundColor = "\033[44m"; break; // синий
        case 6: backgroundColor = "\033[45m"; break; // магента
        case 7: backgroundColor = "\033[40m"; break; // черный
    }
    return textColor + backgroundColor + text + "\033[0m";
}
