#include <iostream>
using namespace std;

typedef struct Dot {
    float x;
    float y;
}Dot;

typedef struct Line {
    struct Dot d1;
    struct Dot d2;
}Line;

bool checkSegment(Dot d1, Dot d2, Dot d3){
    if(d2.x <= max(d1.x, d3.x) && d2.x >= min(d1.x, d3.x) && d2.y <= max(d1.y, d3.y) && d2.y >= min(d1.y, d3.y))
        return true;
    else
        return false;
}

// 0 -> kolinearno, 1 -> u smeru kazaljke na satu, 2 -> suprotno od smera kazaljke na satu
int orientation(Dot d1, Dot d2, Dot d3){
    int result = (d2.y - d1.y) * (d3.x - d2.x) - (d2.x - d1.x) * (d3.y - d2.y);

    if(!result)
        return 0;
    else if(result > 0)
        return 1;
    else
        return 2;
}

bool checkIntersectStatus(int orientation1, int orientation2, int orientation3, int orientation4, Line l1, Line l2){
    // First condition
    if(orientation1 != orientation2 && orientation3 != orientation4)
        return true;

    // Second condition
    if (orientation1 == 0 && checkSegment(l1.d1, l2.d1, l1.d2))
        return true;

    if (orientation2 == 0 && checkSegment(l1.d1, l2.d2, l1.d2))
        return true;

    if (orientation3 == 0 && checkSegment(l1.d2, l1.d1, l2.d2))
        return true;

    if (orientation4 == 0 && checkSegment(l2.d1, l1.d2, l2.d2))
        return true;

    return false;
}

int main(){
    Line lines[2];

    cin >> lines[0].d1.x >> lines[0].d1.y >> lines[0].d2.x >> lines[0].d2.y;
    cin >> lines[1].d1.x >> lines[1].d1.y >> lines[1].d2.x >> lines[1].d2.y;

    int orientation1 = orientation(lines[0].d1, lines[0].d2, lines[1].d1);
    int orientation2 = orientation(lines[0].d1, lines[0].d2, lines[1].d2);
    int orientation3 = orientation(lines[1].d1, lines[1].d2, lines[0].d1);
    int orientation4 = orientation(lines[1].d1, lines[1].d2, lines[0].d2);

    bool result = checkIntersectStatus(orientation1, orientation2, orientation3, orientation4, lines[0], lines[1]);

    if(result)
        cout << "They intersect!";
    else
        cout << "They do not intersect!";

    return 0;
}
