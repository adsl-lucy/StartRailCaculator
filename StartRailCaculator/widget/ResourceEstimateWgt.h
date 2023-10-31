/*****************************************************************************************
**	Copyright(C) <2023-2024> <adsl_lucy>
**
**	Permission is hereby granted, free of charge, to any person obtaining a copy
**	of this software and associated documentation files(the "Software"), to deal
**	in the Software without restriction, including without limitation the rights
**	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
**	copies of the Software, and to permit persons to whom the Software is furnished
**	to do so, subject to the following conditions :
**
**	The above copyright notice and this permission notice shall be included in all
**	copies or substantial portions of the Software.THE SOFTWARE IS PROVIDED "AS IS",
**	WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
**	THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
**	IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
**	OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
**	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
**
*****************************************************************************************/

#ifndef RESOURCE_ESTIMATE_WGT
#define RESOURCE_ESTIMATE_WGT

//ָ��������Դ���㴰�ڣ����Թ��ƿ���ǰ�����Դ״��
//������Ȩ�����ļ�������㣺�ճ�/��С�¿�/ģ������/��Ԩ
//������Ĵ��ڣ���Ҫ����Ŀǰ����治����жϣ����Ժ��Ի
//�����Ȳ�ͳ����Ϊ�������

#include <QWidget>
#include <QDate>
#include <QtCharts>

#include "./ui_ResourceEstimateWgt.h"
#include "../protocol/protocol_StarRailCaculator.h"

class ResourceEstimateWgt :
    public QWidget
{
    Q_OBJECT
public:
	ResourceEstimateWgt(QWidget* parent);
    ~ResourceEstimateWgt();

signals:
    void signal_StartEstimateResource(const St_ResourceEstimateParameter& EstPara);


protected:
    void initPannelWgt();
    void initGraphWgt();

protected:
	//ͳ�ƽ��۴�ӡ�߼�������-1�������ֵ
    void    setCurrentEqualCrystal(int value);
    void    setCurrentEqualTicket(int value);
    void    setStopDayCrystal(int value);
    void    setStopDayTicket(int value);
    void    setStopDayPaidCrystal(int value);
    void    setStopDayEqualCrystal(int value);
    void    setStopDayEqualTicket(int value);
    void    setTotalSmallMonthCardExpense(int value);
    void    setTotalBigMonthCardExpense(int value);
    void    setTotalExpense(int value);

	int		getEqualCrystal(const St_ResourceEstimateDateResult& EstResult);
	int		getEqualTicket(const St_ResourceEstimateDateResult& EstResult);
	int		getPointIndex(const QPointF& ChartPos);

public slots:
    void slot_getErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
    void slot_getResourceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);

	//����ͼ�������ͣ�¼�
	//�����Ч����ͼ����������ź�
	void slot_CrystalChartMouseHovered(const QPointF &point, bool state);
	void slot_TicketChartMouseHovered(const QPointF &point, bool state);

protected slots:
    void slot_startEstmate();
    void slot_resetParameter();
    void slot_clearResult();



private:
	Ui_ResourceEstimateWgt Ui;
    //�洢���ݼ�����
    QVector<St_ResourceEstimateDateResult> m_VecEstResult;

	//ͼ�����
	QDateTimeAxis*  m_axisCrystalDate		= nullptr;
	QDateTimeAxis*  m_axisTicketDate		= nullptr;

	QValueAxis*		m_axisCrystalVal		= nullptr;
	QValueAxis*		m_axisTicketVal			= nullptr;

	//��ʱ���ݴ洢����ͼ�����ʱΪ��ָ��
	QLineSeries*	m_seriesEqualCrystal	= nullptr;	
	QLineSeries*	m_seriesEqualTicket		= nullptr;

	QChart*			m_ChtCrystal			= nullptr;
	QChart*			m_ChtTicket				= nullptr;

	QChartView*		m_ChtViewCrystal		= nullptr;
	QChartView*		m_ChtViewTicket			= nullptr;

	//��ΪQChart�Դ�ͼ��������ж�ʧ�����Զ������һ����λ�õ��м���
	qreal			m_startValue	= 0;//ͼ��ʼ��xֵ
	qreal			m_endValue		= 0;//ͼ�������xֵ
	qreal			m_totalLength	= 0;//ͼ��xֵ���
	qreal			m_interval		= 0;//ͼ��һ����ռ�ݵĳ���
};

#endif