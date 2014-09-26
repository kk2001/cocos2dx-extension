/****************************************************************************
	Copyright (c) 2014 , AdamWu calvinmankor@gmail.com
	All rights reserved.

	Use, modification and distribution are subject to the "New BSD License"
    as listed at <url: http://www.opensource.org/licenses/bsd-license.php >.

	COMPANY:  
	CREATED:  2014��09��15��
****************************************************************************/
#ifndef __VESCROLLVIEW_H__
#define __VESCROLLVIEW_H__


#include "cocos2d.h"
#include "CCScale9Sprite.h"
#include "ContentLayer.h"

USING_NS_CC;

enum ScrollViewType
{
	SCROLLVIEW_NONE = 0,
	SCROLLVIEW_HORIZONTAL,
	SCROLLVIEW_VERTICAL,
};

class VEScrollView : public CCLayer
{
public:
	// implement the "static node()"
	CREATE_FUNC(VEScrollView);

public:
	virtual bool init();

	// set scroll-view type
	void setType(ScrollViewType type) { m_eType=type;};

	// get scroll-view type
	ScrollViewType getType() const {return m_eType;};

	// set view port size
	void setViewSize(CCSize size);
	
	// get view port size
	CCSize getViewSize() const {return m_viewSize;};

    // default implements are used to call script callback if exist
    virtual bool ccTouchBegan(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchMoved(CCTouch *pTouch, CCEvent *pEvent);
    virtual void ccTouchEnded(CCTouch *pTouch, CCEvent *pEvent);
    
    // default implements are used to call script callback if exist
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *pEvent);

	virtual void visit();

	virtual CCRect boundingBox();
    
    void setTouchEnabled(bool val);
    bool getTouchEnabled() const { return m_bTouchEnabled; }
    
	// set scroll view offset
    CCPoint getContentOffset() const;
    void setContentOffset(CCPoint offset);

	// add scroll cell
	void addCell(CCNode* cell);
	void removeCell(CCNode* cell);
	void removeAllCells();
	CCArray* getAllCells();

protected:
	virtual void update(float dt);

	virtual void reArrange();
	virtual void makeScrollBar();
	void fadeScrollBar();
	bool easing(float tY);
	CCNode *touchCheck(CCPoint touchPoint);
protected:
	// scroll-view type
	ScrollViewType m_eType;

	// root node
	CCNode* m_pContainer;

	// view size
	CCSize m_viewSize;

	// content size
	CCSize m_contentSize;

	// touch handle
	bool m_bTouching;
    bool m_bTouchEnabled;
	
	// touch start point
	CCPoint	m_tStartPoint;
	// move offset for each touch move 
	float	m_fTouchOffset;
	// move direction  
	int		m_moveDir;

	// elastic intensity offset
	// [0:normal,>0:stretch]
	float	m_fIntensity;

	// scroll bar 
	CCScale9Sprite* m_scrollBar;
	float m_barScale;
	CCSize m_barSize;
};

#endif //__VESCROLLVIEW_H__