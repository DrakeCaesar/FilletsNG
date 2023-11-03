#include <map>
#include <vector>
#include <utility>
#include "BezierCurves.h"

using std::make_pair;
using std::map;
using std::pair;
using std::vector;

typedef pair<pair<int, int>, pair<int, int>> BezierKey;
typedef map<BezierKey, vector<BezierCurve>> BezierMap;

BezierCurve::BezierCurve(double startX, double startY, double controlX1, double controlY1, double controlX2, double controlY2, double endX, double endY)
    : startX(startX), startY(startY), controlX1(controlX1), controlY1(controlY1), controlX2(controlX2), controlY2(controlY2), endX(endX), endY(endY)
{
}

std::vector<BezierCurve> BezierCurve::getBezierCurvesForPoints(double startX, double startY, double endX, double endY)
{
    BezierKey key = make_pair(make_pair(startX, startY), make_pair(endX, endY));
    auto it = bezierCurves.find(key);

    if (it != bezierCurves.end())
    {
        return it->second;
    }
    else
    {
        return vector<BezierCurve>();
    }
}

static BezierMap bezierCurves;

void initializeBezierMap()
{
    // Now using doubles in the constructor call
    bezierCurves[make_pair(make_pair(320, 121), make_pair(329, 153))] = vector<BezierCurve>{
        BezierCurve(320, 121, 325.90271, 130.54891, 329.05977, 141.77391, 329, 152.99978)};
    bezierCurves[make_pair(make_pair(329, 153), make_pair(320, 189))] = vector<BezierCurve>{
        BezierCurve(329, 152.99978, 328.93367, 165.45693, 325.00944, 177.59417, 320, 188.99989)};
    bezierCurves[make_pair(make_pair(320, 189), make_pair(301, 224))] = vector<BezierCurve>{
        BezierCurve(320, 188.99989, 314.65701, 201.16505, 308.05118, 212.73858, 301, 224)};
    bezierCurves[make_pair(make_pair(301, 224), make_pair(285, 252))] = vector<BezierCurve>{
        BezierCurve(301, 224, 295.28883, 233.12128, 289.24651, 242.11159, 285, 252.00008)};
    bezierCurves[make_pair(make_pair(285, 252), make_pair(279, 286))] = vector<BezierCurve>{
        BezierCurve(285, 252.00008, 280.41274, 262.68207, 278.00487, 274.41754, 279, 286.00018)};
    bezierCurves[make_pair(make_pair(279, 286), make_pair(292, 315))] = vector<BezierCurve>{
        BezierCurve(279, 286.00018, 279.92782, 296.79938, 284.04766, 307.63524, 292, 315.00027)};
    bezierCurves[make_pair(make_pair(292, 315), make_pair(314, 338))] = vector<BezierCurve>{
        BezierCurve(292, 315.00027, 295.99084, 318.69638, 300.78758, 321.4024, 305.02862, 324.80851),
        BezierCurve(305.02862, 324.80851, 307.14914, 326.51157, 309.14026, 328.40175, 310.74236, 330.59954),
        BezierCurve(310.74236, 330.59954, 312.34447, 332.79733, 313.55057, 335.31799, 314, 338.00035)};
    bezierCurves[make_pair(make_pair(314, 338), make_pair(289, 368))] = vector<BezierCurve>{
        BezierCurve(314, 338.00035, 314.57199, 341.41418, 313.88843, 344.97181, 312.40614, 348.09977),
        BezierCurve(312.40614, 348.09977, 310.92383, 351.22774, 308.67368, 353.94781, 306.11164, 356.27533),
        BezierCurve(306.11164, 356.27533, 300.98757, 360.93039, 294.67739, 364.03901, 289, 368.00044)};
    bezierCurves[make_pair(make_pair(289, 368), make_pair(257, 397))] = vector<BezierCurve>{
        BezierCurve(289, 368.00044, 277.1817, 376.24671, 268.29134, 388.04625, 257, 397.00051)};
    bezierCurves[make_pair(make_pair(257, 397), make_pair(217, 415))] = vector<BezierCurve>{
        BezierCurve(257, 397.00051, 245.43407, 406.17255, 231.48843, 412.17532, 217, 415.00057)};
    bezierCurves[make_pair(make_pair(217, 415), make_pair(170, 415))] = vector<BezierCurve>{
        BezierCurve(217, 415.00057, 201.56369, 418.67847, 185.08285, 419.93154, 170, 415.00057)};
    bezierCurves[make_pair(make_pair(170, 415), make_pair(138, 385))] = vector<BezierCurve>{
        BezierCurve(170, 415.00057, 162.79221, 412.64414, 156.0124, 408.88327, 150.40807, 403.77481),
        BezierCurve(150.40807, 403.77481, 144.80374, 398.66634, 140.39892, 392.19437, 138.00042, 385.00048)};
    bezierCurves[make_pair(make_pair(138, 385), make_pair(154, 342))] = vector<BezierCurve>{
        BezierCurve(138.00042, 385.00048, 135.3626, 377.08875, 135.22199, 368.29797, 138.00131, 360.43484),
        BezierCurve(138.00131, 360.43484, 140.78062, 352.5717, 146.53886, 345.72566, 154.00047, 342.00036)};
    bezierCurves[make_pair(make_pair(154, 342), make_pair(192, 351))] = vector<BezierCurve>{
        BezierCurve(154.00047, 342.00036, 160.32108, 338.84471, 167.75731, 337.98388, 174.6317, 339.61205),
        BezierCurve(174.6317, 339.61205, 181.5061, 341.24023, 187.76624, 345.34498, 192, 351.00038)};

    bezierCurves[make_pair(make_pair(289, 368), make_pair(254, 349))] = vector<BezierCurve>{
        BezierCurve(289, 368.00044, 276.12788, 364.33884, 264.08285, 357.80008, 254, 349.00038)};
    bezierCurves[make_pair(make_pair(254, 349), make_pair(226, 317))] = vector<BezierCurve>{
        BezierCurve(254, 349.00038, 243.30592, 339.66723, 234.96499, 328.00482, 226, 317.00028)};
    bezierCurves[make_pair(make_pair(226, 317), make_pair(198, 290))] = vector<BezierCurve>{
        BezierCurve(226, 317.00028, 217.77893, 306.9089, 208.84615, 297.19623, 198, 290.0002)};
    bezierCurves[make_pair(make_pair(198, 290), make_pair(162, 279))] = vector<BezierCurve>{
        BezierCurve(198, 290.0002, 187.36863, 282.94667, 174.74635, 278.43313, 162.00049, 279.00016)};
    bezierCurves[make_pair(make_pair(162, 279), make_pair(129, 290))] = vector<BezierCurve>{
        BezierCurve(162.00049, 279.00016, 150.3069, 279.52038, 139.18163, 284.22497, 129.00039, 290.0002)};
    bezierCurves[make_pair(make_pair(129, 290), make_pair(97, 314))] = vector<BezierCurve>{
        BezierCurve(129.00039, 290.0002, 117.37144, 296.59664, 106.58899, 304.68348, 97.000295, 314.00027)};

    bezierCurves[make_pair(make_pair(292, 315), make_pair(325, 300))] = vector<BezierCurve>{
        BezierCurve(292, 315.00027, 301.40267, 307.18311, 312.92778, 301.9444, 325, 300.00023)};
    bezierCurves[make_pair(make_pair(325, 300), make_pair(359, 304))] = vector<BezierCurve>{
        BezierCurve(325, 300.00023, 336.42482, 298.16031, 348.42543, 299.30021, 359, 304.00024)};
    bezierCurves[make_pair(make_pair(359, 304), make_pair(390, 330))] = vector<BezierCurve>{
        BezierCurve(359, 304.00024, 371.43483, 309.52709, 381.26898, 319.56285, 389.99998, 330.00032)};
    bezierCurves[make_pair(make_pair(390, 330), make_pair(409, 359))] = vector<BezierCurve>{
        BezierCurve(389.99998, 330.00032, 397.44106, 338.89576, 404.38491, 348.36089, 408.99999, 359.00041)};
    bezierCurves[make_pair(make_pair(409, 359), make_pair(414, 387))] = vector<BezierCurve>{
        BezierCurve(408.99999, 359.00041, 412.8146, 367.79454, 414.9853, 377.46495, 414.00002, 387)};
    bezierCurves[make_pair(make_pair(414, 387), make_pair(390, 417))] = vector<BezierCurve>{
        BezierCurve(414.00002, 387, 413.29653, 393.80801, 410.94331, 400.50728, 406.80427, 405.95817),
        BezierCurve(406.80427, 405.95817, 402.66525, 411.40906, 396.68761, 415.54418, 389.99998, 417.00002)};
    bezierCurves[make_pair(make_pair(390, 417), make_pair(357, 404))] = vector<BezierCurve>{
        BezierCurve(389.99998, 417.00002, 383.94607, 418.31791, 377.51582, 417.41547, 371.82169, 414.97339),
        BezierCurve(371.82169, 414.97339, 366.12755, 412.53132, 361.14322, 408.60657, 357, 403.99999)};
    bezierCurves[make_pair(make_pair(357, 404), make_pair(343, 369))] = vector<BezierCurve>{
        BezierCurve(357, 403.99999, 348.42118, 394.46176, 343.36585, 381.82343, 343, 369)};

    bezierCurves[make_pair(make_pair(359, 304), make_pair(393, 298))] = vector<BezierCurve>{
        BezierCurve(359, 304.00024, 369.48429, 298.90252, 381.40414, 296.79901, 392.99999, 298.00022)};
    bezierCurves[make_pair(make_pair(393, 298), make_pair(425, 313))] = vector<BezierCurve>{
        BezierCurve(392.99999, 298.00022, 404.97467, 299.24067, 416.80659, 304.17988, 424.99999, 313.00027)};
    bezierCurves[make_pair(make_pair(425, 313), make_pair(445, 345))] = vector<BezierCurve>{
        BezierCurve(424.99999, 313.00027, 433.58056, 322.23743, 437.55932, 334.82257, 444.99999, 345.00037)};
    bezierCurves[make_pair(make_pair(445, 345), make_pair(475, 365))] = vector<BezierCurve>{
        BezierCurve(444.99999, 345.00037, 452.25232, 354.92051, 462.98492, 362.42298, 475, 365.00042)};
    bezierCurves[make_pair(make_pair(475, 365), make_pair(510, 360))] = vector<BezierCurve>{
        BezierCurve(475, 365.00042, 486.73974, 367.5188, 499.2177, 365.28294, 510.00001, 360.00041)};
    bezierCurves[make_pair(make_pair(510, 360), make_pair(539, 332))] = vector<BezierCurve>{
        BezierCurve(510.00001, 360.00041, 522.26518, 353.9914, 532.5645, 344.04719, 539, 332.00033)};

    bezierCurves[make_pair(make_pair(279, 286), make_pair(312, 266))] = vector<BezierCurve>{
        BezierCurve(279, 286.00018, 287.30379, 275.84995, 299.15943, 268.66469, 312, 266.00013)};
    bezierCurves[make_pair(make_pair(312, 266), make_pair(350, 265))] = vector<BezierCurve>{
        BezierCurve(312, 266.00013, 324.43564, 263.41959, 337.29943, 264.99268, 350, 265.00012)};
    bezierCurves[make_pair(make_pair(350, 265), make_pair(388, 264))] = vector<BezierCurve>{
        BezierCurve(350, 265.00012, 362.67504, 265.00754, 375.33722, 263.4427, 388, 264)};
    bezierCurves[make_pair(make_pair(388, 264), make_pair(424, 269))] = vector<BezierCurve>{
        BezierCurve(388, 264, 400.11229, 264.53308, 412.04233, 266.99873, 424, 269.00014)};
    bezierCurves[make_pair(make_pair(424, 269), make_pair(458, 275))] = vector<BezierCurve>{
        BezierCurve(424, 269.00014, 435.35301, 270.90034, 446.78895, 272.38986, 458.00001, 275.00015)};
    bezierCurves[make_pair(make_pair(458, 275), make_pair(490, 283))] = vector<BezierCurve>{
        BezierCurve(458.00001, 275.00015, 468.71115, 277.49404, 479.18505, 281.00398, 490.00001, 283.00018)};
    bezierCurves[make_pair(make_pair(490, 283), make_pair(525, 286))] = vector<BezierCurve>{
        BezierCurve(490.00001, 283.00018, 501.52526, 285.12747, 513.29036, 285.5093, 525.00002, 286.00018)};
    bezierCurves[make_pair(make_pair(525, 286), make_pair(567, 297))] = vector<BezierCurve>{
        BezierCurve(525.00002, 286.00018, 532.35919, 286.30869, 539.75364, 286.66698, 546.9633, 288.17488),
        BezierCurve(546.9633, 288.17488, 554.17296, 289.68279, 561.24708, 292.40058, 566.99999, 297.00022)};
    bezierCurves[make_pair(make_pair(567, 297), make_pair(580, 330))] = vector<BezierCurve>{
        BezierCurve(566.99999, 297.00022, 571.83281, 300.86422, 575.63091, 306.01038, 577.89882, 311.7674),
        BezierCurve(577.89882, 311.7674, 580.16674, 317.52442, 580.89895, 323.87835, 579.99998, 330.00032)};

    bezierCurves[make_pair(make_pair(567, 297), make_pair(574, 267))] = vector<BezierCurve>{
        BezierCurve(567.00002, 297.00022, 567.00002, 297.00022, 573.99999, 267.00013, 573.99999, 267.00013)};

    bezierCurves[make_pair(make_pair(285, 252), make_pair(247, 234))] = vector<BezierCurve>{
        BezierCurve(285, 252, 272.07798, 246.56014, 259.39503, 240.55243, 247, 234.00003)};
    bezierCurves[make_pair(make_pair(247, 234), make_pair(219, 217))] = vector<BezierCurve>{
        BezierCurve(247, 234.00003, 237.33841, 228.8926, 227.82943, 223.43995, 219, 216.99997)};
    bezierCurves[make_pair(make_pair(219, 217), make_pair(192, 192))] = vector<BezierCurve>{
        BezierCurve(219, 216.99997, 209.06897, 209.75652, 200.04588, 201.29274, 192, 191.9999)};
    bezierCurves[make_pair(make_pair(192, 192), make_pair(171, 161))] = vector<BezierCurve>{
        BezierCurve(192, 191.9999, 183.80918, 182.53965, 176.60646, 172.1872, 171, 161)};
    bezierCurves[make_pair(make_pair(171, 161), make_pair(161, 125))] = vector<BezierCurve>{
        BezierCurve(171, 161, 165.37494, 149.7757, 161.34415, 137.54992, 161.00049, 124.9997)};
    bezierCurves[make_pair(make_pair(161, 125), make_pair(175, 81))] = vector<BezierCurve>{
        BezierCurve(161.00049, 124.9997, 160.57191, 109.34797, 165.99365, 93.807598, 175, 80.99956)};
    bezierCurves[make_pair(make_pair(175, 81), make_pair(207, 52))] = vector<BezierCurve>{
        BezierCurve(175, 80.99956, 183.33894, 69.140651, 194.61967, 59.542621, 207, 51.99947)};
    bezierCurves[make_pair(make_pair(207, 52), make_pair(244, 44))] = vector<BezierCurve>{
        BezierCurve(207, 51.99947, 212.5651, 48.608736, 218.42615, 45.587864, 224.72318, 43.910088),
        BezierCurve(224.72318, 43.910088, 231.02021, 42.232313, 237.81132, 41.957956, 244, 43.999448)};
    bezierCurves[make_pair(make_pair(244, 44), make_pair(266, 77))] = vector<BezierCurve>{
        BezierCurve(244, 43.999448, 250.67673, 46.201937, 256.34219, 51.039807, 260.07433, 56.998062),
        BezierCurve(260.07433, 56.998062, 263.80647, 62.956316, 265.6732, 69.976526, 266, 76.999549)};
    bezierCurves[make_pair(make_pair(266, 77), make_pair(251, 115))] = vector<BezierCurve>{
        BezierCurve(266, 76.999549, 266.65222, 91.015879, 261.05011, 105.20792, 251, 114.99966)};

    bezierCurves[make_pair(make_pair(192, 192), make_pair(167, 222))] = vector<BezierCurve>{
        BezierCurve(192, 191.9999, 186.09122, 203.72583, 177.46816, 214.07353, 167, 221.99999)};
    bezierCurves[make_pair(make_pair(167, 222), make_pair(132, 238))] = vector<BezierCurve>{
        BezierCurve(167, 221.99999, 156.6927, 229.80466, 144.63246, 235.24605, 132.0004, 238.00004)};
    bezierCurves[make_pair(make_pair(132, 238), make_pair(95, 236))] = vector<BezierCurve>{
        BezierCurve(132.0004, 238.00004, 119.74584, 240.67173, 106.60468, 240.75927, 95.000291, 236.00003)};
    bezierCurves[make_pair(make_pair(95, 236), make_pair(70, 210))] = vector<BezierCurve>{
        BezierCurve(95.000291, 236.00003, 83.533019, 231.29703, 74.019159, 221.72448, 70.000212, 209.99995)};
    bezierCurves[make_pair(make_pair(70, 210), make_pair(78, 169))] = vector<BezierCurve>{
        BezierCurve(70.000212, 209.99995, 67.638874, 203.11118, 67.164012, 195.59427, 68.57897, 188.45081),
        BezierCurve(68.57897, 188.45081, 69.993923, 181.30736, 73.288854, 174.55266, 78.000238, 168.99983)};
    bezierCurves[make_pair(make_pair(78, 169), make_pair(111, 159))] = vector<BezierCurve>{
        BezierCurve(78.000238, 168.99983, 81.996836, 164.28944, 87.082988, 160.39818, 92.927229, 158.39684),
        BezierCurve(92.927229, 158.39684, 98.77147, 156.3955, 105.39806, 156.39692, 111.00034, 158.9998)};
    bezierCurves[make_pair(make_pair(111, 159), make_pair(118, 192))] = vector<BezierCurve>{
        BezierCurve(111.00034, 158.9998, 116.90971, 161.74536, 121.39352, 167.37664, 122.74563, 173.75085),
        BezierCurve(122.74563, 173.75085, 124.09773, 180.12506, 122.28621, 187.09171, 118.00036, 191.9999)};

    bezierCurves[make_pair(make_pair(167, 222), make_pair(198, 244))] = vector<BezierCurve>{
        BezierCurve(167, 221.99999, 167, 221.99999, 198, 244.00006, 198, 244.00006)};

    bezierCurves[make_pair(make_pair(301, 224), make_pair(340, 228))] = vector<BezierCurve>{
        BezierCurve(301, 224, 313.83645, 226.55084, 326.913, 227.89202, 340, 228)};
    bezierCurves[make_pair(make_pair(340, 228), make_pair(381, 224))] = vector<BezierCurve>{
        BezierCurve(340, 228, 353.75826, 228.11352, 367.54208, 226.86132, 380.99999, 224)};
    bezierCurves[make_pair(make_pair(381, 224), make_pair(422, 210))] = vector<BezierCurve>{
        BezierCurve(380.99999, 224, 395.15788, 220.98985, 408.92289, 216.20442, 422.00002, 209.99995)};
    bezierCurves[make_pair(make_pair(422, 210), make_pair(456, 189))] = vector<BezierCurve>{
        BezierCurve(422.00002, 209.99995, 434.06181, 204.27722, 445.56847, 197.33176, 455.99999, 188.99989)};
    bezierCurves[make_pair(make_pair(456, 189), make_pair(483, 158))] = vector<BezierCurve>{
        BezierCurve(455.99999, 188.99989, 466.78139, 180.38855, 476.49179, 170.16685, 483, 157.9998)};
    bezierCurves[make_pair(make_pair(483, 158), make_pair(491, 119))] = vector<BezierCurve>{
        BezierCurve(483, 157.9998, 489.35435, 146.11841, 492.49897, 132.3899, 491, 118.99968)};
    bezierCurves[make_pair(make_pair(491, 119), make_pair(477, 84))] = vector<BezierCurve>{
        BezierCurve(491, 118.99968, 489.58804, 106.38678, 484.15919, 94.479305, 476.99998, 83.999569)};
    bezierCurves[make_pair(make_pair(477, 84), make_pair(446, 58))] = vector<BezierCurve>{
        BezierCurve(476.99998, 83.999569, 469.25979, 72.669338, 458.97041, 62.477664, 446.00001, 57.999488)};
    bezierCurves[make_pair(make_pair(446, 58), make_pair(402, 61))] = vector<BezierCurve>{
        BezierCurve(446.00001, 57.999488, 431.81208, 53.100937, 416.00159, 55.590724, 402.00002, 60.998999)};
    bezierCurves[make_pair(make_pair(402, 61), make_pair(372, 88))] = vector<BezierCurve>{
        BezierCurve(402.00002, 60.998999, 395.49857, 63.51026, 389.17578, 66.669505, 383.79859, 71.103589),
        BezierCurve(383.79859, 71.103589, 378.4214, 75.537672, 374.01417, 81.327374, 372, 87.99958)};
    bezierCurves[make_pair(make_pair(372, 88), make_pair(391, 124))] = vector<BezierCurve>{
        BezierCurve(372, 87.99958, 369.82617, 95.200672, 370.60267, 103.24559, 374.11365, 109.89798),
        BezierCurve(374.11365, 109.89798, 377.62462, 116.55037, 383.82826, 121.73098, 391.00001, 123.99969)};

    bezierCurves[make_pair(make_pair(456, 189), make_pair(464, 227))] = vector<BezierCurve>{
        BezierCurve(455.99999, 188.99989, 454.47688, 202.08429, 457.33077, 215.6403, 463.99999, 227.00001)};
    bezierCurves[make_pair(make_pair(464, 227), make_pair(487, 252))] = vector<BezierCurve>{
        BezierCurve(463.99999, 227.00001, 469.76451, 236.8187, 478.15395, 244.83173, 487, 252)};
    bezierCurves[make_pair(make_pair(487, 252), make_pair(521, 261))] = vector<BezierCurve>{
        BezierCurve(487, 252, 491.84907, 255.92939, 496.97042, 259.70273, 502.85566, 261.78067),
        BezierCurve(502.85566, 261.78067, 505.79826, 262.81965, 508.91373, 263.41803, 512.03359, 263.34844),
        BezierCurve(512.03359, 263.34844, 515.15345, 263.27885, 518.27848, 262.52707, 521.00002, 261.00011)};
    bezierCurves[make_pair(make_pair(521, 261), make_pair(541, 232))] = vector<BezierCurve>{
        BezierCurve(521.00002, 261.00011, 523.59372, 259.54488, 525.76957, 257.42148, 527.55763, 255.04495),
        BezierCurve(527.55763, 255.04495, 529.34565, 252.66842, 530.764, 250.03596, 532.07074, 247.36437),
        BezierCurve(532.07074, 247.36437, 534.68422, 242.02119, 536.95508, 236.36103, 541.00001, 232.00002)};
    bezierCurves[make_pair(make_pair(541, 232), make_pair(571, 210))] = vector<BezierCurve>{
        BezierCurve(541.00001, 232.00002, 545.26156, 227.40549, 551.09868, 224.6742, 556.64167, 221.7509),
        BezierCurve(556.64167, 221.7509, 562.18463, 218.82759, 567.8011, 215.38859, 570.99999, 209.99995)};
    bezierCurves[make_pair(make_pair(571, 210), make_pair(550, 175))] = vector<BezierCurve>{
        BezierCurve(570.99999, 209.99995, 573.0431, 206.55828, 573.9528, 202.47918, 573.70747, 198.48428),
        BezierCurve(573.70747, 198.48428, 573.46217, 194.48938, 572.0806, 190.58868, 569.87558, 187.24844),
        BezierCurve(569.87558, 187.24844, 565.4655, 180.56796, 557.89248, 176.33654, 550, 174.99985)};
    bezierCurves[make_pair(make_pair(550, 175), make_pair(510, 199))] = vector<BezierCurve>{
        BezierCurve(550, 174.99985, 541.65421, 173.58637, 532.82219, 175.25131, 525.56385, 179.60635),
        BezierCurve(525.56385, 179.60635, 518.30547, 183.96139, 512.68019, 190.97089, 510.00001, 199)};
}

// Ensure the map is initialized before main() runs
struct BezierMapInitializer
{
    BezierMapInitializer() { initializeBezierMap(); }
} bezierMapInitializer;
