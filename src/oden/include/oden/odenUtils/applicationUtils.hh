#pragma once

#include <string>

namespace oden {
namespace applicationUtils {

/// @brief Prints information message.
/// @param message is the actual message to print.
void _oden_internal_messageInfo(const std::string &message);

/// @brief Prints warning message.
/// @param file is expanded by macro to the raising point of the message.
/// @param line is expanded by macro to the raising point of the message.
/// @param message is the actual message to print.
void _oden_internal_messageWarning(const std::string &file, unsigned int line,
                                   const std::string &message);

/// @brief Prints an error message, which causes exit.
/// @param file is expanded by macro to the raising point of the message.
/// @param line is expanded by macro to the raising point of the message.
/// @param message is the actual message to print.
void _oden_internal_messageError(const std::string &file, unsigned int line,
                                 const std::string &message);

void _oden_internal_messageWarning(const std::string &message);

#define messageInfo(message)                                                   \
  oden::applicationUtils::_oden_internal_messageInfo((message))

#define messageInfoIf(condition, message)                                      \
  if (condition)                                                               \
  oden::applicationUtils::_oden_internal_messageInfo((message))

#define messageWarning(message)                                                \
  oden::applicationUtils::_oden_internal_messageWarning((message))

#define messageWarningIf(condition, message)                                      \
  if (condition)                                                               \
  oden::applicationUtils::_oden_internal_messageWarning((message))

#define messageError(message)                                                  \
  oden::applicationUtils::_oden_internal_messageError(__FILE__, __LINE__,      \
                                                      (message))

#define messageErrorIf(condition, message)                                     \
  if (condition)                                                               \
  oden::applicationUtils::_oden_internal_messageError(__FILE__, __LINE__,      \
                                                      (message))
} // namespace applicationUtils
} // namespace oden
