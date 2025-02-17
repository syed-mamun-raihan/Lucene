#pragma once
#include "stringhelper.h"
#include <memory>
#include <string>
#include <deque>

// C++ NOTE: Forward class declarations:
#include  "core/src/java/org/apache/lucene/document/Document.h"

#include  "core/src/java/org/apache/lucene/search/Query.h"
#include  "core/src/java/org/apache/lucene/geo/Polygon.h"

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
namespace org::apache::lucene::search
{

using Document = org::apache::lucene::document::Document;
using BaseGeoPointTestCase = org::apache::lucene::geo::BaseGeoPointTestCase;
using Polygon = org::apache::lucene::geo::Polygon;

class TestLatLonPointQueries : public BaseGeoPointTestCase
{
  GET_CLASS_NAME(TestLatLonPointQueries)

protected:
  void addPointToDoc(const std::wstring &field, std::shared_ptr<Document> doc,
                     double lat, double lon) override;

  std::shared_ptr<Query> newRectQuery(const std::wstring &field, double minLat,
                                      double maxLat, double minLon,
                                      double maxLon) override;

  std::shared_ptr<Query> newDistanceQuery(const std::wstring &field,
                                          double centerLat, double centerLon,
                                          double radiusMeters) override;

  std::shared_ptr<Query>
  newPolygonQuery(const std::wstring &field,
                  std::deque<Polygon> &polygons) override;

  double quantizeLat(double latRaw) override;

  double quantizeLon(double lonRaw) override;

public:
  virtual void testDistanceQueryWithInvertedIntersection() ;

protected:
  std::shared_ptr<TestLatLonPointQueries> shared_from_this()
  {
    return std::static_pointer_cast<TestLatLonPointQueries>(
        org.apache.lucene.geo.BaseGeoPointTestCase::shared_from_this());
  }
};

} // #include  "core/src/java/org/apache/lucene/search/
