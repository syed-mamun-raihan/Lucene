#pragma once
#include "stringhelper.h"
#include <memory>
#include <stdexcept>
#include <string>
#include <unordered_map>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/queryparser/flexible/core/config/QueryConfigHandler.h"

#include  "core/src/java/org/apache/lucene/queryparser/flexible/core/config/FieldConfig.h"

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
namespace org::apache::lucene::queryparser::flexible::standard::config
{

using FieldConfig =
    org::apache::lucene::queryparser::flexible::core::config::FieldConfig;
using FieldConfigListener = org::apache::lucene::queryparser::flexible::core::
    config::FieldConfigListener;
using QueryConfigHandler = org::apache::lucene::queryparser::flexible::core::
    config::QueryConfigHandler;

/**
 * This listener is used to listen to {@link FieldConfig} requests in
 * {@link QueryConfigHandler} and add {@link ConfigurationKeys#POINTS_CONFIG}
 * based on the {@link ConfigurationKeys#POINTS_CONFIG_MAP} set in the
 * {@link QueryConfigHandler}.
 *
 * @see PointsConfig
 * @see QueryConfigHandler
 * @see ConfigurationKeys#POINTS_CONFIG
 * @see ConfigurationKeys#POINTS_CONFIG_MAP
 */
class PointsConfigListener
    : public std::enable_shared_from_this<PointsConfigListener>,
      public FieldConfigListener
{
  GET_CLASS_NAME(PointsConfigListener)

private:
  const std::shared_ptr<QueryConfigHandler> config;

  /**
   * Constructs a {@link PointsConfigListener} object using the given {@link
   * QueryConfigHandler}.
   *
   * @param config the {@link QueryConfigHandler} it will listen too
   */
public:
  PointsConfigListener(std::shared_ptr<QueryConfigHandler> config);

  void buildFieldConfig(std::shared_ptr<FieldConfig> fieldConfig) override;
};

} // #include  "core/src/java/org/apache/lucene/queryparser/flexible/standard/config/
