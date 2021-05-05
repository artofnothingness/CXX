#include "iostream"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/spdlog.h"

void basic_logfile_example() {
  try {
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs/basic-log.txt");
    spdlog::get("basic_logger")->info("cool file logger");
  } catch (const spdlog::spdlog_ex &ex) {
    std::cout << "Log init failed: " << ex.what() << std::endl;
  }
}

int main() {
  basic_logfile_example();
  return 0;
}

