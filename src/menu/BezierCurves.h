#ifndef BEZIER_CURVES_H
#define BEZIER_CURVES_H

#include <map>
#include <utility>
#include <vector>

typedef std::pair<std::pair<int, int>, std::pair<int, int>> BezierKey;

typedef std::map<BezierKey, std::vector<class BezierCurve>> BezierMap;

class BezierCurve
{
private:
public:
  double startX, startY, controlX1, controlY1, controlX2, controlY2, endX, endY;

  BezierCurve(double startX, double startY, double controlX1, double controlY1, double controlX2, double controlY2,
              double endX, double endY);

  static std::vector<BezierCurve> getBezierCurvesForPoints(double startX, double startY, double endX, double endY);
};

extern BezierMap bezierCurves;

void initializeBezierMap();

#endif // BEZIER_CURVES_H
