#pragma once
#include "stringbuilder.h"
#include "stringhelper.h"
#include <any>
#include <limits>
#include <memory>
#include <optional>
#include <stdexcept>
#include <string>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/spatial3d/geom/GeoDistanceShape.h"

namespace org::apache::lucene::search
{
template <typename T>
class FieldComparator;
}

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
namespace org::apache::lucene::spatial3d
{

using FieldComparator = org::apache::lucene::search::FieldComparator;
using SortField = org::apache::lucene::search::SortField;
using GeoDistanceShape = org::apache::lucene::spatial3d::geom::GeoDistanceShape;

/**
 * Sorts by distance from an origin location.
 */
class Geo3DPointSortField final : public SortField
{
  GET_CLASS_NAME(Geo3DPointSortField)
public:
  const std::shared_ptr<GeoDistanceShape> distanceShape;

  Geo3DPointSortField(const std::wstring &field,
                      std::shared_ptr<GeoDistanceShape> distanceShape);

  // C++ TODO: Java wildcard generics are not converted to C++:
  // ORIGINAL LINE: @Override public org.apache.lucene.search.FieldComparator<?>
  // getComparator(int numHits, int sortPos)
  std::shared_ptr < FieldComparator <
      ? >> getComparator(int numHits, int sortPos) override;

  std::optional<double> getMissingValue() override;

  void setMissingValue(std::any missingValue) override;

  virtual int hashCode();

  bool equals(std::any obj) override;

  virtual std::wstring toString();

protected:
  std::shared_ptr<Geo3DPointSortField> shared_from_this()
  {
    return std::static_pointer_cast<Geo3DPointSortField>(
        org.apache.lucene.search.SortField::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/spatial3d/
