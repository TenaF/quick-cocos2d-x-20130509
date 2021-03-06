/****************************************************************************
Copyright (c) 2010 cocos2d-x.org

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/

#ifndef __CCGEMETRY_H__
#define __CCGEMETRY_H__

#include "platform/CCPlatformMacros.h"
#include "CCObject.h"
#include <vector>

using namespace std;

NS_CC_BEGIN

/**
 * @addtogroup data_structures
 * @{
 */

class CC_DLL CCPoint
{
public:
    float x;
    float y;

public:
    CCPoint();
    CCPoint(float x, float y);
    CCPoint(const CCPoint& other);
    CCPoint& operator= (const CCPoint& other);
    void setPoint(float x, float y);
    bool equals(const CCPoint& target) const;
};

/** An Array that contain points.
 */
class CC_DLL CCPointArray : public CCObject
{
public:
    
    /** creates and initializes a Points array with capacity */
    static CCPointArray* create(unsigned int capacity);
    
    ~CCPointArray(void);
    CCPointArray(void);
    
    /** initializes a Catmull Rom config with a capacity hint */
    bool initWithCapacity(unsigned int capacity);
    
    /** appends a point */
    void add(CCPoint point);
    
    /** inserts a point at index */
    void insert(CCPoint &point, unsigned int index);
    
    /** replaces an existing point at index */
    void replace(CCPoint &point, unsigned int index);
    
    /** get the value of a point at a given index */
    CCPoint get(unsigned int index);
    
    /** deletes a point at a given index */
    void remove(unsigned int index);
    
    /** deletes all points */
    void removeAll(void);
    
    /** returns the number of objects of the point array */
    unsigned int count(void);
    
    /** returns a new copy of the array reversed. User is responsible for releasing this copy */
    CCPointArray* reverse(void);
    
    /** reverse the current point array inline, without generating a new one */
    void reverseInline(void);
    
    virtual CCObject* copyWithZone(CCZone *zone);
    
    const std::vector<CCPoint*>* getPoints(void);
    void setPoints(std::vector<CCPoint*> *points);
    
    /** returns a array of points, User must delete [] this array */
    CCPoint *fetchPoints(void);
    
private:
    /** Array that contains the points */
    std::vector<CCPoint*> *m_pPoints;
};

class CC_DLL CCSize
{
public:
    float width;
    float height;

public:
    CCSize();
    CCSize(float width, float height);
    CCSize(const CCSize& other);
    CCSize& operator= (const CCSize& other);
    void setSize(float width, float height);
    bool equals(const CCSize& target) const;
};

class CC_DLL CCRect
{
public:
    CCPoint origin;
    CCSize  size;

public:
    CCRect();    
    CCRect(float x, float y, float width, float height);
    CCRect(const CCRect& other);
    CCRect& operator= (const CCRect& other); 
    void setRect(float x, float y, float width, float height);
    float getMinX() const; /// return the leftmost x-value of current rect
    float getMidX() const; /// return the midpoint x-value of current rect
    float getMaxX() const; /// return the rightmost x-value of current rect
    float getMinY() const; /// return the bottommost y-value of current rect
    float getMidY() const; /// return the midpoint y-value of current rect
    float getMaxY() const; /// return the topmost y-value of current rect
    bool equals(const CCRect& rect) const;   
    bool containsPoint(const CCPoint& point) const;
    bool intersectsRect(const CCRect& rect) const;
};


#define CCPointMake(x, y) CCPoint((float)(x), (float)(y))
#define CCSizeMake(width, height) CCSize((float)(width), (float)(height))
#define CCRectMake(x, y, width, height) CCRect((float)(x), (float)(y), (float)(width), (float)(height))


const CCPoint CCPointZero = CCPointMake(0,0);

/* The "zero" size -- equivalent to CCSizeMake(0, 0). */ 
const CCSize CCSizeZero = CCSizeMake(0,0);

/* The "zero" rectangle -- equivalent to CCRectMake(0, 0, 0, 0). */ 
const CCRect CCRectZero = CCRectMake(0,0,0,0);

// end of data_structure group
/// @}

NS_CC_END

#endif // __CCGEMETRY_H__
