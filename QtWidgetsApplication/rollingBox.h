#pragma once

#include <QWidget>
#include <QMouseEvent>
#include <QColor>
#include<QPainter>
#include<QTime>

class RollingBox : public QWidget
{
	Q_OBJECT

public:
	explicit RollingBox(QWidget *parent = 0);
	~RollingBox();
	//获取中间值
	inline int getValue() { return m_nCurrentValue; }
	//设置中间值
	inline void setValue(int nValue) { m_nCurrentValue = nValue; }
	//设置滚动的步长
	inline void setStep(int nStep) { m_nStep = nStep; }
	//设置显示个数
	inline void setDevice(int nDevice) { m_nDevice = nDevice; }
	//设置显示边界
	void setRang(int nMin, int nMax);

protected:
	void wheelEvent(QWheelEvent* event);
	void paintEvent(QPaintEvent* event);
	//绘制中间选择
	void paintLine(QPainter* pPainter);
	//绘制文字
	void paintText(QPainter* pPainter, int nValue, int nOffSet, int nFontSize);

signals:
	void sigCurrentValueChange(int nValue);

private:
	//当前选中值
	int m_nCurrentValue;
	//偏离值
	int m_nOffSet;
	//滚动的最大值
	int m_nMax;
	//滚动的最小值
	int m_nMin;
	//显示的数量
	int m_nDevice;
	//滚动的步长
	int m_nStep; 
};