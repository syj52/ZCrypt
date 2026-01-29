#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

class Logger {
public:
    // 日志级别
    enum Level {
        DEBUG,
        INFO,
        WARN,
        ERROR
    };

    // 单例模式：全局只有一个 Logger 实例
    static Logger& getInstance() {
        static Logger instance;
        return instance;
    }

    // 设置输出目标：控制台或文件
    void setOutputToConsole() { outputToConsole = true; outputToFile = false; }
    void setOutputToFile(const std::string& filename) { 
        logFile.open(filename, std::ios::app); // 追加模式
        outputToFile = logFile.is_open();
        outputToConsole = false;
    }

    // 核心日志函数
    void log(Level level, const std::string& message);

private:
    Logger() : outputToConsole(true), outputToFile(false) {}
    ~Logger() { if (logFile.is_open()) logFile.close(); }

    std::ofstream logFile;
    bool outputToConsole;
    bool outputToFile;

    // 将级别转换为字符串
    std::string levelToString(Level level);
    
    // 获取当前时间字符串
    std::string getCurrentTime();
};

// 定义宏，方便使用
#define LOG_DEBUG(msg) Logger::getInstance().log(Logger::DEBUG, msg)
#define LOG_INFO(msg)  Logger::getInstance().log(Logger::INFO, msg)
#define LOG_WARN(msg)  Logger::getInstance().log(Logger::WARN, msg)
#define LOG_ERROR(msg) Logger::getInstance().log(Logger::ERROR, msg)

#endif