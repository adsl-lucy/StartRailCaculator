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

//中介器，容纳模块核心计算逻辑
//为了以后方便把dota2/apex工具融进来所以把主窗口放到这个类里面

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
	//资源计算器错误信号
	void signal_ResouceEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//资源计算器结果信号
	void signal_ResouceEstResult(const QVector<St_ResourceEstimateDateResult>& EstResultVec);

	//N步之内出货概率模拟进度，0为刚开始，100为完成
	void signal_UpdateCardPoolEstmateProgress(const int Val);
	//N步之内出货概率模拟结果
	void signal_CardPoolEstResult(const St_CardPoolEstimateResult& EstResult);

	//资源投入收益模拟进度，0为刚开始，100为完成
	void signal_UpdateInvestmentEstimateProgress(const int val);
	//投资与收益结果统计
	void signal_InvestmentEstimateResult(const St_InvectmentEstimateResult& result);
	//有效圣遗物计算错误信号
	void signal_RelicEstErrorMsg(const EN_StarRailErrorNum ErrNum, const QString& ErrMsg);
	//有效圣遗物计算模拟进度，0为刚开始，100为完成
	void signal_UpdateRelicEstimateProgress(const int val);
	//有效圣遗物计算结果
	void signal_RelicEstResult(const St_ValidRelicEstimateResult& EstResult);

//计算中间函数
protected:
	//检查资源计算器输入错误，返回错误码
	const EN_StarRailErrorNum	checkResourceEstInputErr(const St_ResourceEstimateParameter& EstPara);
	//发送资源计算错误信号：错误码+具体错误文案
	void  sendResourceEstErrorMsg(const EN_StarRailErrorNum ErrNum);

	//抽一次卡,返回抽卡结果
	//第一个参数表示卡池类型
	//第二个参数表示上一个金是不是歪了（如果歪了，那么下一个金就必然是UP，反之依照卡池的概率出UP金）
	//第三个参数为距离上一个金的距离，如果上一个结果是金，那么距离为1，当角色池距离为90时必出金，武器池距离为80时必出金
	//对于重复实验中的某一次实验，其结束后重新生成的engine需要通过切换随机种子来更改随机数表来获得更好的随机性
	En_DrawCardResult DrawCardAtOnce(EN_CardPoolType poolType, bool wrongGoldBefore, int distanceToLastGold, std::default_random_engine& engine);



	//进行一次完整的停止实验，不停的抽卡直到获得UP角色/武器位置，返回出货位置（角色：1-180，武器：1-160）
	//参数意义同上一个函数,其中areadyInTicket表示已经投入的票数
	int DrawCardUntilGetUp(EN_CardPoolType poolType, bool wrongGoldBefore, int areadyInTicket, std::default_random_engine& engine);

	//进行一次N角色M武器/N武器M角色的抽卡实验,返回<N，M>
	//返回参数格式为<N角色,M武器>/<N武器,M角色>，参数错误返回<-1,-1>
	//每进行一次实验建议切换随机数引擎的种子
	QPair<int, int> DrawCardNPoolAMPoolB(En_PoolTransfromType transfromType, int largestTicket, std::default_random_engine& engine,
		bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket,int N,int M);

	//进行一次N发角色M发武器/N发武器M发角色的抽卡实验,返回<N，M>
	//输入参数只能是<N角色,M武器>/<N武器,M角色>返回形式相同
	//输入参数错误返回<-1,-1>
	//每进行一次实验建议切换随机数引擎的种子
	QPair<int, int> DrawCardNTPoolAMTPoolB(En_PoolTransfromType transfromType, int largestTicket, std::default_random_engine& engine,
		bool wrongGoldCharacterbefore, int areadyInCharacterPoolTicket, bool wrongGoldWeaponBefore, int areadyInWeaponPoolTicket, int N, int M);

	//检查有效遗物计算输入错误，返回错误码
	const EN_StarRailErrorNum	checkRelicEstInputErr(const St_RelicValidEstimatePara& EstPara);
	//发送有效遗物计算错误信号：错误码+具体错误文案
	void  sendRelicEstErrorMsg(const EN_StarRailErrorNum ErrNum);


protected slots:

	//估算资源变化具体逻辑
	//不论输入成功与否都会发送错误码和错误消息
	//输入失败不会进行计算
	//计算细节：
	//每天清空日常获得60水
	//小月卡失效后第一天购买小月卡，当天会获得 300古老梦华 以及90水，小月卡30天后失效
	//默认每周第一天清空模拟宇宙，获得最高级奖励225氵
	//默认每月1日去商店兑换一次5抽
	//14天刷新一次深渊，默认刷新深渊后第一天清空允许的深渊层数
	//版本42天更新一次，更新当天送300氵运维，300氵修BUG，版本更新后会刷新大月卡
	//大月卡刷新后第一天购买大月卡（68元），大月卡每周升10级（最快速度），于第10级获得1抽，第20级获得1抽，第30级获得两抽，第50级获得680氵
	void slot_startResourceEstmate(const St_ResourceEstimateParameter& EstPara);



	//N抽之内出货概率
	//角色池基础概率0.6%，出金为up概率为50%，小保底90，大保底180
	//武器池基础概率0.8%，出金为up概率为75%，小保底80，大保底160
	//角色池出一个金最多90抽，武器池出一个金最多80抽
	//模拟方法为蒙特卡洛方法：
	//1.重复停止实验100000次
	//2.记录每个位置的停止次数
	//3.将每个位置停止次数和总实验次数的比视为该位置的停止概率
	void slot_startCardPoolEstimate(const St_CardPoolEstimatePara& EstPara);


	//资源收益计算具体逻辑
	//模拟10万次资源投入后的结果获得一个概率矩阵
	//矩阵的第N行对应事件获得N个UP角色，第0行对应事件没有角色
	//矩阵的第N列对应事件获得N个UP武器，第0列对应事件没有武器
	//矩阵的值对应事件的概率，原则上返回的矩阵每一行长度一致，但是部分概率过小的情形可能会忽略（设为0）
	void slot_startInvestmentIncomeEstimate(const St_InvestmentEstimatePara& EstPara);


	//开始有效圣遗物统计
	void slot_startRelicValidEstimate(const St_RelicValidEstimatePara& EstPara);



private:
	static StarRailMediator* m_instance ;

	StarRailMainFrame* m_mainFrame = nullptr;

};


























#endif // !CACULATOR_STARRAILMEDIATOR
