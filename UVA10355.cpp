#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
#include <algorithm>

using namespace std;

struct Point {
    double x, y, z;
    Point(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
};

struct Sphere {
    Point center;
    double radius;
    Sphere(double x, double y, double z, double r) : center(x, y, z), radius(r) {}
};

// 計算兩點之間的距離
double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

// 計算直線與球體的交點
vector<Point> getIntersections(const Point& start, const Point& end, const Sphere& sphere) {
    vector<Point> intersections;
    
    // 直線參數方程: P = start + t * (end - start)
    Point direction(end.x - start.x, end.y - start.y, end.z - start.z);
    Point toCenter(start.x - sphere.center.x, start.y - sphere.center.y, start.z - sphere.center.z);
    
    // 二次方程的係數: at² + bt + c = 0
    double a = pow(direction.x, 2) + pow(direction.y, 2) + pow(direction.z, 2);
    double b = 2 * (toCenter.x * direction.x + toCenter.y * direction.y + toCenter.z * direction.z);
    double c = pow(toCenter.x, 2) + pow(toCenter.y, 2) + pow(toCenter.z, 2) - pow(sphere.radius, 2);
    
    double discriminant = b * b - 4 * a * c;
    
    // 如果判別式大於等於0，表示有交點
    if (discriminant >= 0) {
        double t1 = (-b - sqrt(discriminant)) / (2 * a);
        double t2 = (-b + sqrt(discriminant)) / (2 * a);
        
        // 只取在線段範圍內的交點 (0 <= t <= 1)
        if (t1 >= 0 && t1 <= 1) {
            Point p1(start.x + t1 * direction.x, 
                    start.y + t1 * direction.y, 
                    start.z + t1 * direction.z);
            intersections.push_back(p1);
        }
        
        if (t2 >= 0 && t2 <= 1 && abs(t2 - t1) > 1e-9) {
            Point p2(start.x + t2 * direction.x, 
                    start.y + t2 * direction.y, 
                    start.z + t2 * direction.z);
            intersections.push_back(p2);
        }
    }
    
    return intersections;
}

int main() {
    string cityName;
    
    while (cin >> cityName) {
        // 讀取起點和終點座標
        Point start, end;
        cin >> start.x >> start.y >> start.z >> end.x >> end.y >> end.z;
        
        // 讀取污染區域數量
        int numRegions;
        cin >> numRegions;
        
        // 讀取所有污染區域
        vector<Sphere> regions;
        for (int i = 0; i < numRegions; i++) {
            double x, y, z, r;
            cin >> x >> y >> z >> r;
            regions.push_back(Sphere(x, y, z, r));
        }
        
        // 收集所有關鍵點（起點、終點、交點）
        vector<Point> keyPoints;
        keyPoints.push_back(start);
        keyPoints.push_back(end);
        
        // 找出所有與污染區域的交點
        for (const auto& region : regions) {
            vector<Point> intersections = getIntersections(start, end, region);
            for (const auto& point : intersections) {
                keyPoints.push_back(point);
            }
        }
        
        // 按照從起點到終點的順序排序關鍵點
        Point direction(end.x - start.x, end.y - start.y, end.z - start.z);
        sort(keyPoints.begin(), keyPoints.end(), [&](const Point& a, const Point& b) {
            // 計算點在直線上的參數值
            double ta = 0, tb = 0;
            if (abs(direction.x) > 1e-9) {
                ta = (a.x - start.x) / direction.x;
                tb = (b.x - start.x) / direction.x;
            }
            else if (abs(direction.y) > 1e-9) {
                ta = (a.y - start.y) / direction.y;
                tb = (b.y - start.y) / direction.y;
            }
            else if (abs(direction.z) > 1e-9) {
                ta = (a.z - start.z) / direction.z;
                tb = (b.z - start.z) / direction.z;
            }
            return ta < tb;
        });
        
        // 計算路徑長度
        double totalPath = distance(start, end);
        double pollutedPath = 0.0;
        
        // 檢查每個線段是否在污染區域內
        for (int i = 0; i < keyPoints.size() - 1; i++) {
            Point segmentStart = keyPoints[i];
            Point segmentEnd = keyPoints[i + 1];
            Point segmentMid((segmentStart.x + segmentEnd.x) / 2,
                           (segmentStart.y + segmentEnd.y) / 2,
                           (segmentStart.z + segmentEnd.z) / 2);
            
            // 檢查線段中點是否在任何污染區域內
            for (const auto& region : regions) {
                if (distance(segmentMid, region.center) <= region.radius) {
                    pollutedPath += distance(segmentStart, segmentEnd);
                    break;
                }
            }
        }
        
        // 計算污染路徑的百分比
        double percentage = (pollutedPath / totalPath) * 100.0;
        
        // 輸出結果
        cout << cityName << "\n";
        cout << fixed << setprecision(2) << percentage << "\n";
    }
    
    return 0;
}