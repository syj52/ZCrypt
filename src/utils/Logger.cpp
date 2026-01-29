#include "Logger.h"
#include <iomanip>

void Logger::log(Level level, const std::string& message) {
    std::ostringstream oss;
    oss << "[" << getCurrentTime() << "] "
        << "[" << levelToString(level) << "] "
        << message;

    std::string logEntry = oss.str();

    // 输出到控制台
    if (outputToConsole) {
        // 根据级别使用不同颜色（Windows 下可选，Linux 默认支持）
        switch (level) {
            case ERROR: std::cout << "\033[31m"; break; // 红色
            case WARN:  std::cout << "\033[33m"; break; // 黄色
            case DEBUG: std::cout << "\033[34m"; break; // 蓝色
            default: break;
        }
        std::cout << logEntry << std::endl;
        std::cout << "\033[0m"; // 重置颜色
    }

    // 输出到文件
    if (outputToFile && logFile.is_open()) {
        logFile << logEntry << std::endl;
        logFile.flush(); // 立即写入，防止程序崩溃丢失日志
    }
}

std::string Logger::levelToString(Level level) {
    switch (level) {
        case DEBUG: return "DEBUG";
        case INFO:  return "INFO";
        case WARN:  return "WARN";
        case ERROR: return "ERROR";
        default:    return "UNKNOWN";
    }
}

std::string Logger::getCurrentTime() {
    auto now = std::time(nullptr);
    auto* tm = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}