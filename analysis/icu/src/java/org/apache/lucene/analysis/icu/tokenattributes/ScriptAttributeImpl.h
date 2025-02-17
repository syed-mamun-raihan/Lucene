#pragma once
#include "../../../../../../../../../../core/src/java/org/apache/lucene/util/AttributeImpl.h"
#include "ScriptAttribute.h"
#include "stringhelper.h"
#include <any>
#include <memory>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/util/AttributeImpl.h"

#include  "core/src/java/org/apache/lucene/util/AttributeReflector.h"

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
namespace org::apache::lucene::analysis::icu::tokenattributes
{

using AttributeImpl = org::apache::lucene::util::AttributeImpl;
using AttributeReflector = org::apache::lucene::util::AttributeReflector;

using com::ibm::icu::lang::UScript;

/**
 * Implementation of {@link ScriptAttribute} that stores the script
 * as an integer.
 * @lucene.experimental
 */
class ScriptAttributeImpl : public AttributeImpl,
                            public ScriptAttribute,
                            public Cloneable
{
  GET_CLASS_NAME(ScriptAttributeImpl)
private:
  int code = UScript::COMMON;

  /** Initializes this attribute with <code>UScript.COMMON</code> */
public:
  ScriptAttributeImpl();

  int getCode() override;

  void setCode(int code) override;

  std::wstring getName() override;

  std::wstring getShortName() override;

  void clear() override;

  void copyTo(std::shared_ptr<AttributeImpl> target) override;

  bool equals(std::any other) override;

  virtual int hashCode();

  void reflectWith(AttributeReflector reflector) override;

protected:
  std::shared_ptr<ScriptAttributeImpl> shared_from_this()
  {
    return std::static_pointer_cast<ScriptAttributeImpl>(
        org.apache.lucene.util.AttributeImpl::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/analysis/icu/tokenattributes/
