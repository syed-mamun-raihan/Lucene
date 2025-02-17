#pragma once
#include "exceptionhelper.h"
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <deque>

/*
 * Licensed to the Syed Mamun Raihan (sraihan.com) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * sraihan.com licenses this file to You under GPLv3 License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     https://www.gnu.org/licenses/gpl-3.0.en.html
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
namespace org::apache::lucene::analysis::cn::smart
{

/**
 * Manages analysis data configuration for SmartChineseAnalyzer
 * <p>
 * SmartChineseAnalyzer has a built-in dictionary and stopword deque out-of-box.
 * </p>
 * @lucene.experimental
 */
class AnalyzerProfile : public std::enable_shared_from_this<AnalyzerProfile>
{
  GET_CLASS_NAME(AnalyzerProfile)

  /**
   * Global indicating the configured analysis data directory
   */
public:
  static std::wstring ANALYSIS_DATA_DIR;

private:
  class StaticConstructor
      : public std::enable_shared_from_this<StaticConstructor>
  {
    GET_CLASS_NAME(StaticConstructor)
  public:
    StaticConstructor();
  };

private:
  static AnalyzerProfile::StaticConstructor staticConstructor;

  static void init();

  static std::wstring getAnalysisDataDir(std::shared_ptr<Path> propFile);
};

} // #include  "core/src/java/org/apache/lucene/analysis/cn/smart/
