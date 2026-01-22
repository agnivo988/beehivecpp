#include <vector>
#include <cmath>

void generateHexPrism(std::vector<float>& v)
{
    float r = 0.5f, h = 0.4f;

    for(int i=0;i<6;i++){
        float a = i * 60.0f * 3.14159f / 180;
        float b = (i+1)%6 * 60.0f * 3.14159f / 180;

        float x1=r*cos(a), y1=r*sin(a);
        float x2=r*cos(b), y2=r*sin(b);

        // side quad (2 triangles)
        v.insert(v.end(), {
            x1,y1,h, x2,y2,h, x2,y2,-h,
            x1,y1,h, x2,y2,-h, x1,y1,-h
        });
    }
}
