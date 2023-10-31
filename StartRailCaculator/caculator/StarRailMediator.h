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

#ifndef CACULATOR_STARRAILMEDIATOR
#define CACULATOR_STARRAILMEDIATOR

//�н���������ģ����ļ����߼�
//Ϊ���Ժ󷽱��dota2/apex�����ڽ������԰������ڷŵ����������

#include <QObject>
#include <ctime>
#include <random>

#include "../widget/StarRailMainFrame.h"
#include "../protocol/RelicResult.h"

class StarRailMediator : public QObject
{
	StarRailMediator();
	~StarRailMediator();

	Q_OBJECT
public:
	static StarRailMediator* instance();

	QWidget* getMainFrame() { return m_mainFrame; };

protected:
	void initUi();
	void initSignalSlots();

public: signals:
	//��Դ�����������ź�
	void signal_ResouceEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//��Դ����������ź�
	void signal_ResouceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);

	//N��֮�ڳ�������ģ����ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateCardPoolEstmateProgress(const int Val);
	//N��֮�ڳ�������ģ����
	void signal_CardPoolEstResult(const St_CardPoolEstimateResult& EstResult);

	//��ԴͶ������ģ����ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateInvestmentEstimateProgress(const int val);
	//Ͷ����������ͳ��
	void signal_InvestmentEstimateResult(const St_InvectmentEstimateResult& result);
	//��Чʥ�����������ź�
	void signal_RelicEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//��Чʥ�������ģ����ȣ�0Ϊ�տ�ʼ��100Ϊ���
	void signal_UpdateRelicEstimateProgress(const int val);
	//��Чʥ���������
	void signal_RelicEstResult(const St_ValidRelicEstimateResult& EstResult);

//�����м亯��
protected:
	//�����Դ������������󣬷��ش�����
	const EN_StarRailErrorNum	checkResourceEstInputErr(const St_ResourceEstimateParameter& EstPara);
	//������Դ��������źţ�������+��������İ�
	void  sendResourceEstErrorMsg(const EN_StarRailErrorNum ErrNum);

	//��һ�ο�,���س鿨���
	//��һ��������ʾ��������
	//�ڶ���������ʾ��һ�����ǲ������ˣ�������ˣ���ô��һ����ͱ�Ȼ��UP����֮���տ��صĸ��ʳ�UP��
	//����������Ϊ������һ����ľ��룬�����һ������ǽ���ô����Ϊ1������ɫ�ؾ���Ϊ90ʱ�س��������ؾ���Ϊ80ʱ�س���
	//�����ظ�ʵ���е�ĳһ��ʵ�飬��������������ɵ�engine��Ҫͨ���л�������������������������ø��õ������
	En_DrawCardResult DrawCardAtOnce(EN_CardPoolType poolType, bool wrongGoldBefore, int distanceToLastGold, std::default_random_engine& engine);



	//����һ��������ֹͣʵ�飬��ͣ�ĳ鿨ֱ�����UP��ɫ/����λ�ã����س���λ�ã���ɫ��1-180��������1-160��
	//��������ͬ��һ������,����areadyInTicket��ʾ�Ѿ�Ͷ���Ʊ��
	int DrawCardUntilGetUp(EN_CardPoolType poolType, bool wrongGoldBefore, int areadyInTicket, std::default_random_engine& engine);

	//����һ��N��ɫM����/N����M��ɫ�ĳ鿨ʵ��,����<N��M>
	//���ز�����ʽΪ<N��ɫ,M����>/<N����,M��ɫ>���������󷵻�<-1,-1>
	//ÿ����һ��ʵ�齨���л���������������
	QPair<int, int> DrawCardNPoolAMPoolB(En_PoolTransfromType transfromType, int largestTicket, std::default_random_engine& engine,
		bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket,int N,int M);

	//����һ��N����ɫM������/N������M����ɫ�ĳ鿨ʵ��,����<N��M>
	//�������ֻ����<N��ɫ,M����>/<N����,M��ɫ>������ʽ��ͬ
	//����������󷵻�<-1,-1>
	//ÿ����һ��ʵ�齨���л���������������
	QPair<int, int> DrawCardNTPoolAMTPoolB(En_PoolTransfromType transfromType, int largestTicket, std::default_random_engine& engine,
		bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket, int N, int M);

	//�����Ч�������������󣬷��ش�����
	const EN_StarRailErrorNum	checkRelicEstInputErr(const St_RelicValidEstimatePara& EstPara);
	//������Ч�����������źţ�������+��������İ�
	void  sendRelicEstErrorMsg(const EN_StarRailErrorNum ErrNum);


protected slots:

	//������Դ�仯�����߼�
	//��������ɹ���񶼻ᷢ�ʹ�����ʹ�����Ϣ
	//����ʧ�ܲ�����м���
	//����ϸ�ڣ�
	//ÿ������ճ����60ˮ
	//С�¿�ʧЧ���һ�칺��С�¿���������� 300�����λ� �Լ�90ˮ��С�¿�30���ʧЧ
	//Ĭ��ÿ�ܵ�һ�����ģ�����棬�����߼�����225��
	//Ĭ��ÿ��1��ȥ�̵�һ�һ��5��
	//14��ˢ��һ����Ԩ��Ĭ��ˢ����Ԩ���һ������������Ԩ����
	//�汾42�����һ�Σ����µ�����300����ά��300����BUG���汾���º��ˢ�´��¿�
	//���¿�ˢ�º��һ�칺����¿���68Ԫ�������¿�ÿ����10��������ٶȣ����ڵ�10�����1�飬��20�����1�飬��30��������飬��50�����680��
	void slot_startResourceEstmate(const St_ResourceEstimateParameter& EstPara);



	//N��֮�ڳ�������
	//��ɫ�ػ�������0.6%������Ϊup����Ϊ50%��С����90���󱣵�180
	//�����ػ�������0.8%������Ϊup����Ϊ75%��С����80���󱣵�160
	//��ɫ�س�һ�������90�飬�����س�һ�������80��
	//ģ�ⷽ��Ϊ���ؿ��巽����
	//1.�ظ�ֹͣʵ��100000��
	//2.��¼ÿ��λ�õ�ֹͣ����
	//3.��ÿ��λ��ֹͣ��������ʵ������ı���Ϊ��λ�õ�ֹͣ����
	void slot_startCardPoolEstimate(const St_CardPoolEstimatePara& EstPara);


	//��Դ�����������߼�
	//ģ��10�����ԴͶ���Ľ�����һ�����ʾ���
	//����ĵ�N�ж�Ӧ�¼����N��UP��ɫ����0�ж�Ӧ�¼�û�н�ɫ
	//����ĵ�N�ж�Ӧ�¼����N��UP��������0�ж�Ӧ�¼�û������
	//�����ֵ��Ӧ�¼��ĸ��ʣ�ԭ���Ϸ��صľ���ÿһ�г���һ�£����ǲ��ָ��ʹ�С�����ο��ܻ���ԣ���Ϊ0��
	void slot_startInvestmentIncomeEstimate(const St_InvestmentEstimatePara& EstPara);


	//��ʼ��Чʥ����ͳ��
	void slot_startRelicValidEstimate(const St_RelicValidEstimatePara& EstPara);



private:
	static StarRailMediator* m_instance ;

	StarRailMainFrame* m_mainFrame = nullptr;

};


























#endif // !CACULATOR_STARRAILMEDIATOR
