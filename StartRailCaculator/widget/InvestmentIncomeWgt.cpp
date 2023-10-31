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

#include "InvestmentIncomeWgt.h"
#pragma execution_character_set("utf-8")

InvestmentIncomeWgt::InvestmentIncomeWgt(QWidget* parent)
	:QWidget(parent)
{
	Ui.setupUi(this);
	initUi();
	init3DGraph();
	slot_resetParameter();
	//Ĭ��0+1����������ȫ��Ҫ
	Ui.radioButton_getAll->setChecked(true);
	slot_drawCardObjChanged();
}

InvestmentIncomeWgt::~InvestmentIncomeWgt()
{
}

void InvestmentIncomeWgt::slot_getInvestmentIncomeResult(const St_InvectmentEstimateResult & result)
{	
	//��ӡ�������
	setInputCrystal(result.inputCrystal);
	setInputTicket(result.inputTicket);
	setDrawCardType(result.drawCardType, result.poolTransformType, result.N, result.M);

	//��ֵ����3Dͼ��
	QSize matrixSize	= result.ProbDensityMatrix.getMatrixSize();
	//�ӿɶ��ԵĽǶ�������������һ��������Ա�������������
	int maxCharacterNum = matrixSize.height() - 1;
	int maxWeaponNum	= matrixSize.width() - 1;

	QStringList RowNameList;

	for (int currentRowNum = 0; currentRowNum <= maxCharacterNum; currentRowNum++)
	{
		QString currentRowName = QString::number(currentRowNum) + QString("����ɫ");
		RowNameList << currentRowName;
	}
	m_axisCharacterNum->setLabels(RowNameList);

	QStringList columnNameList;

	for (int currentColumn = 0; currentColumn <= maxWeaponNum; currentColumn++)
	{
		QString currentRowName = QString::number(currentColumn) + QString("������");
		columnNameList << currentRowName;
	}
	m_axisWeaponNum->setLabels(columnNameList);

	m_dataProxy->resetArray();

	for (int currentRowNum = 0; currentRowNum <= maxCharacterNum; currentRowNum++)
	{
		QBarDataRow* currentRowVec = new QBarDataRow();

		for (int currentColumn = 0; currentColumn <= maxWeaponNum; currentColumn++)
		{
			double currentProbability = result.ProbDensityMatrix.getConstValueAt(currentRowNum, currentColumn);
			QBarDataItem currentItem(currentProbability * 100);
			currentRowVec->push_back(currentItem);
		}
		m_dataProxy->addRow(currentRowVec);
	}

	//����ͼ���ǩ����+��ӡͳ�ƽ��
	switch (result.drawCardType)
	{
		case En_DrawCardType::characterOnly:
		{
			m_seriesProbabilityDenseMatrix->setItemLabelFormat("@rowIdx ����ɫ�ĸ���: %.2f%%");
			setNoUpCharacterProb(result.NoUpCharacterPorb);
			setUpCharacterGetExpectation(result.UpCharacterGetTimeExpectation);
			setNoUpWeaponValue(-1);
			setUpWeaponGetExpectation(-1);
		}break;
		case En_DrawCardType::waeponOnly:
		{
			m_seriesProbabilityDenseMatrix->setItemLabelFormat(" @colIdx �������ĸ���: %.2f%%");
			setNoUpWeaponValue(result.NoUpWeaponProb);
			setUpWeaponGetExpectation(result.UpWeaponGetExpectation);
			setNoUpCharacterProb(-1);
			setUpCharacterGetExpectation(-1);
		}break;
		case En_DrawCardType::getAll:
		{
			m_seriesProbabilityDenseMatrix->setItemLabelFormat("@rowIdx ����ɫ @colIdx �������ĸ���: %.2f%%");
			setNoUpWeaponValue(result.NoUpWeaponProb);
			setUpWeaponGetExpectation(result.UpWeaponGetExpectation);
			setNoUpCharacterProb(result.NoUpCharacterPorb);
			setUpCharacterGetExpectation(result.UpCharacterGetTimeExpectation);
		}break;
	};

	enablePanel(true);
	slot_transformTypeChanged();	
}

void InvestmentIncomeWgt::initUi()
{
	m_btnGroupDrawCardObj = new QButtonGroup(this);
	m_btnGroupDrawCardObj->setExclusive(true);
	m_btnGroupDrawCardObj->addButton(Ui.radioButton_CharacterOnly,0);
	m_btnGroupDrawCardObj->addButton(Ui.radioButton_WeaponOnly,1);
	m_btnGroupDrawCardObj->addButton(Ui.radioButton_getAll,2);
	Ui.radioButton_CharacterOnly->setChecked(true);

	m_btnGroupPoolTransformType = new QButtonGroup(this);
	m_btnGroupPoolTransformType->setExclusive(true);
	m_btnGroupPoolTransformType->addButton(Ui.radioButton_NCharacterMWeapon,0);
	m_btnGroupPoolTransformType->addButton(Ui.radioButton_NWeaponMChacter,1);
	m_btnGroupPoolTransformType->addButton(Ui.radioButton_NTickCharacterMTickWeapon,2);
	m_btnGroupPoolTransformType->addButton(Ui.radioButton_NTickWeaponMTickCharacter,3);
	Ui.radioButton_NCharacterMWeapon->setChecked(true);

	Ui.label_ErrMsg->clear();
	Ui.progressBar_EstmateState->setValue(0);

	connect(m_btnGroupDrawCardObj,			QOverload<int>::of(&QButtonGroup::buttonClicked), this, &InvestmentIncomeWgt::slot_drawCardObjChanged);
	connect(m_btnGroupPoolTransformType,	QOverload<int>::of(&QButtonGroup::buttonClicked), this, &InvestmentIncomeWgt::slot_transformTypeChanged);

	connect(Ui.pushButton_startEstimate,	&QPushButton::clicked, this, &InvestmentIncomeWgt::slot_startEstimate);
	connect(Ui.pushButton_resetPara,		&QPushButton::clicked, this, &InvestmentIncomeWgt::slot_resetParameter);
	connect(Ui.pushButton_clearResult,		&QPushButton::clicked, this, &InvestmentIncomeWgt::slot_clearResult);

}

void InvestmentIncomeWgt::init3DGraph()
{

	m_Graph = new Q3DBars();
	QWidget *container = QWidget::createWindowContainer(m_Graph);
	QHBoxLayout* graphLayout = new QHBoxLayout(Ui.widget_3dGraph);
	graphLayout->addWidget(container);

	m_camera = m_Graph->scene()->activeCamera();
	m_camera->setMinZoomLevel(50);
	m_camera->setMaxZoomLevel(200);

	m_camera->setXRotation(-42);
	m_camera->setYRotation(36);
	m_camera->setZoomLevel(86);

	connect(m_camera, &Q3DCamera::xRotationChanged, this, &InvestmentIncomeWgt::slot_cameraHAngleChanged);
	connect(m_camera, &Q3DCamera::yRotationChanged, this, &InvestmentIncomeWgt::slot_cameraVAanglechanged);
	connect(m_camera, &Q3DCamera::zoomLevelChanged, this, &InvestmentIncomeWgt::slot_cameraZoomLevelChanged);

	connect(Ui.horizontalSlider_Hangle, &QSlider::sliderMoved, this, &InvestmentIncomeWgt::slot_HAngleSliderValueChanged);
	connect(Ui.horizontalSlider_Vangle, &QSlider::sliderMoved, this, &InvestmentIncomeWgt::slot_VAngleSliderValueChanged);
	connect(Ui.horizontalSlider_Zoom,	&QSlider::sliderMoved, this, &InvestmentIncomeWgt::slot_ZoomLevelSliderValueChanged);

	m_axisCharacterNum	= new QCategory3DAxis();
	m_axisCharacterNum->setTitle("UP��ɫ����");
	m_axisCharacterNum->setTitleVisible(true);
	QStringList characterAxisSList{ "0����ɫ",};
	m_axisCharacterNum->setLabels(characterAxisSList);
	m_Graph->setRowAxis(m_axisCharacterNum);

	m_axisWeaponNum		= new QCategory3DAxis();
	m_axisWeaponNum->setTitle("UP��������");
	m_axisWeaponNum->setTitleVisible(true);
	QStringList weaponAxisSList{ "0������" };
	m_axisWeaponNum->setLabels(weaponAxisSList);
	m_Graph->setColumnAxis(m_axisWeaponNum);

	m_axisProbability = new QValue3DAxis();
	m_axisProbability->setRange(0, 100);
	m_axisProbability->setLabelFormat("%.2f%%");
	m_Graph->setValueAxis(m_axisProbability);

	m_seriesProbabilityDenseMatrix = new QBar3DSeries();
	m_dataProxy = new QBarDataProxy();
	m_seriesProbabilityDenseMatrix->setDataProxy(m_dataProxy);

	m_Graph->addSeries(m_seriesProbabilityDenseMatrix);

}



void InvestmentIncomeWgt::enablePanel(bool state)
{
	Ui.spinBox_crystal->setEnabled(state);
	Ui.spinBox_ticket->setEnabled(state);
	Ui.groupBox_drawCardType->setEnabled(state);
	Ui.groupBox_PoolState->setEnabled(state);
	Ui.groupBox_PoolTransformType->setEnabled(state);
	Ui.pushButton_startEstimate->setEnabled(state);
	Ui.pushButton_resetPara->setEnabled(state);
	Ui.pushButton_clearResult->setEnabled(state);
}

void InvestmentIncomeWgt::setInputCrystal(int value)
{
	if (value == -1)
	{
		Ui.label_InputCyrstal->setText("Ͷ������:");
	}
	else
	{
		Ui.label_InputCyrstal->setText(QString("Ͷ������:") + QString::number(value));
	}
}

void InvestmentIncomeWgt::setInputTicket(int value)
{
	if (value == -1)
	{
		Ui.label_inputTicket->setText("Ͷ��רƱ:");
	}
	else
	{
		Ui.label_inputTicket->setText(QString("Ͷ��רƱ:") + QString::number(value));
	}
}

void InvestmentIncomeWgt::setDrawCardType(En_DrawCardType drawCardType, En_PoolTransfromType poolTransformType, int N, int M)
{
	QString title("�鿨��ʽ:");
	QString appendText;
	switch (drawCardType)
	{
		case En_DrawCardType::characterOnly	: appendText = QString("ֻ���ɫ"); break;
		case En_DrawCardType::waeponOnly	: appendText = QString("ֻ������"); break;
		case En_DrawCardType::getAll:
		{
			switch (poolTransformType)
			{
				case En_PoolTransfromType::NCharacterMWeapon:
					appendText = QString("�ȳ�") + QString::number(N) + QString("����ɫ�ٳ�")	+ QString::number(M) + QString("������");	break;
				case En_PoolTransfromType::NWeaponMCharacter:
					appendText = QString("�ȳ�") + QString::number(N) + QString("�������ٳ�")	+ QString::number(M) + QString("����ɫ");	break;
				case En_PoolTransfromType::NTCharacterMTWeapon:
					appendText = QString("�ȳ�") + QString::number(N) + QString("����ɫ���ٳ�") + QString::number(M) + QString("��������"); break;
				case En_PoolTransfromType::NTWeaponMTCharacter:
					appendText = QString("�ȳ�") + QString::number(N) + QString("���������ٳ�") + QString::number(M) + QString("����ɫ��"); break;
			}
		}
	}
	Ui.label_drawCardType->setText(title + appendText);
}

void InvestmentIncomeWgt::setNoUpCharacterProb(double prob)
{
	if ( prob < 0 )
	{
		Ui.label_NoUpCharacterProb->setText("Up��ɫ��������:");
	}
	else
	{
		Ui.label_NoUpCharacterProb->setText(QString("Up��ɫ��������:") + QString::asprintf("%.2f%%", prob * 100));
	}
}

void InvestmentIncomeWgt::setNoUpWeaponValue(double prob)
{
	if ( prob < 0)
	{
		Ui.label_NoUpWeaponProb->setText("Up������������:");
	}
	else
	{
		Ui.label_NoUpWeaponProb->setText(QString("Up������������:") + QString::asprintf("%.2f%%", prob * 100));
	}
}

void InvestmentIncomeWgt::setUpCharacterGetExpectation(double expectation)
{
	if (expectation < 0)
	{
		Ui.label_getChaExpectation->setText("Up��ɫ��ȡ����:");
	}
	else
	{
		Ui.label_getChaExpectation->setText(QString("Up��ɫ��ȡ����:") + QString::asprintf("%.2f", expectation));
	}
}

void InvestmentIncomeWgt::setUpWeaponGetExpectation(double expectation)
{
	if (expectation < 0)
	{
		Ui.label_getWeaponExpectation->setText("Up������ȡ����:");
	}
	else
	{
		Ui.label_getWeaponExpectation->setText(QString("Up������ȡ����:") + QString::asprintf("%.2f", expectation));
	}
}

void InvestmentIncomeWgt::slot_transformTypeChanged()
{
	if (Ui.groupBox_PoolTransformType->isEnabled() == false)
	{
		return;
	}

	if (Ui.radioButton_NCharacterMWeapon->isChecked())
	{
		Ui.spinBox_NChaMWea_Cha->setEnabled(true);
		Ui.spinBox_NChaMWea_Wea->setEnabled(true);
	}
	else
	{
		Ui.spinBox_NChaMWea_Cha->setEnabled(false);
		Ui.spinBox_NChaMWea_Wea->setEnabled(false);
	}

	if (Ui.radioButton_NWeaponMChacter->isChecked())
	{
		Ui.spinBox_NWeaMCha_Cha->setEnabled(true);
		Ui.spinBox_NWeaMCha_Wea->setEnabled(true);;
	}
	else
	{
		Ui.spinBox_NWeaMCha_Cha->setEnabled(false);
		Ui.spinBox_NWeaMCha_Wea->setEnabled(false);
	}

	if (Ui.radioButton_NTickCharacterMTickWeapon->isChecked())
	{
		Ui.spinBox_NTChaMTWea_Cha->setEnabled(true);
		Ui.spinBox_NTChaMTWea_Wea->setEnabled(true);
	}
	else
	{
		Ui.spinBox_NTChaMTWea_Cha->setEnabled(false);
		Ui.spinBox_NTChaMTWea_Wea->setEnabled(false);
	}

	if (Ui.radioButton_NTickWeaponMTickCharacter->isChecked())
	{
		Ui.spinBox_NTWeaMTCha_Cha->setEnabled(true);
		Ui.spinBox_NTWeaMTCha_Wea->setEnabled(true);
	}
	else
	{
		Ui.spinBox_NTWeaMTCha_Cha->setEnabled(false);
		Ui.spinBox_NTWeaMTCha_Wea->setEnabled(false);
	}

}

void InvestmentIncomeWgt::slot_resetParameter()
{
	Ui.spinBox_crystal->setValue(0);
	Ui.spinBox_ticket->setValue(0);
	Ui.radioButton_getAll->setChecked(true);
	slot_drawCardObjChanged();
	Ui.checkBox_lastGoldCharacterWrong->setChecked(false);
	Ui.spinBox_charPoolAreadyInTicket->setValue(0);
	Ui.checkBox_lastGoldWeaponWrong->setChecked(false);
	Ui.spinBox_WeaponPoolAreadyInTicket->setValue(0);
	Ui.radioButton_NCharacterMWeapon->setChecked(true);
	slot_transformTypeChanged();

	Ui.spinBox_NChaMWea_Cha->setValue(1);
	Ui.spinBox_NChaMWea_Wea->setValue(1);
	Ui.spinBox_NWeaMCha_Cha->setValue(1);
	Ui.spinBox_NWeaMCha_Wea->setValue(1);
	Ui.spinBox_NTChaMTWea_Cha->setValue(10);
	Ui.spinBox_NTChaMTWea_Wea->setValue(10);
	Ui.spinBox_NTWeaMTCha_Cha->setValue(10);
	Ui.spinBox_NTWeaMTCha_Wea->setValue(10);

}

void InvestmentIncomeWgt::slot_clearResult()
{
	slot_updateEstimateProgress(0);
	setInputCrystal(-1);
	setInputTicket(-1);
	Ui.label_drawCardType->setText("�鿨��ʽ:");
	setNoUpCharacterProb(-1);
	setNoUpWeaponValue(-1);
	setUpCharacterGetExpectation(-1);
	setUpWeaponGetExpectation(-1);
	m_dataProxy->resetArray();
}

void InvestmentIncomeWgt::slot_startEstimate()
{
	enablePanel(false);
	St_InvestmentEstimatePara para;

	para.inputCrystal = Ui.spinBox_crystal->value();
	para.inputTicket = Ui.spinBox_ticket->value();

	switch (m_btnGroupDrawCardObj->checkedId())
	{
		case 0:	para.drawCardType = En_DrawCardType::characterOnly;		break;
		case 1:	para.drawCardType = En_DrawCardType::waeponOnly;		break;
		case 2:	para.drawCardType = En_DrawCardType::getAll;			break;
	}

	para.lastGoldCharacterWrong			= Ui.checkBox_lastGoldCharacterWrong->isChecked();
	para.areadyInCharacterPoolTicket	= Ui.spinBox_charPoolAreadyInTicket->value();
	para.lastGoldWeaponWrong			= Ui.checkBox_lastGoldWeaponWrong->isChecked();
	para.areadyInWeaponPoolTicket		= Ui.spinBox_WeaponPoolAreadyInTicket->value();

	switch (m_btnGroupPoolTransformType->checkedId())
	{
		case 0: 
		{
			para.poolTransformType = En_PoolTransfromType::NCharacterMWeapon;
			para.N = Ui.spinBox_NChaMWea_Cha->value();
			para.M = Ui.spinBox_NChaMWea_Wea->value();
		}break;
		case 1: 
		{
			para.poolTransformType = En_PoolTransfromType::NWeaponMCharacter;
			para.N = Ui.spinBox_NWeaMCha_Wea->value();
			para.M = Ui.spinBox_NWeaMCha_Cha->value();
		}break;
		case 2:
		{
			para.poolTransformType = En_PoolTransfromType::NTCharacterMTWeapon;
			para.N = Ui.spinBox_NTChaMTWea_Cha->value();
			para.M = Ui.spinBox_NTChaMTWea_Wea->value();
		}break;
		case 3: 
		{
			para.poolTransformType = En_PoolTransfromType::NTWeaponMTCharacter;
			para.N = Ui.spinBox_NTWeaMTCha_Wea->value();
			para.M = Ui.spinBox_NTWeaMTCha_Cha->value();
		}break;
	}

	emit signal_StartInvestmentIncomeEstimate(para);

}

void InvestmentIncomeWgt::slot_cameraHAngleChanged(double degree)
{
	//qDebug() << "slot_rotateX:" << degree;
	Ui.horizontalSlider_Hangle->setValue(degree);
}

void InvestmentIncomeWgt::slot_cameraVAanglechanged(double degree)
{
	//qDebug() << "slot_rotateY:" << degree;
	Ui.horizontalSlider_Vangle->setValue(degree);
}

void InvestmentIncomeWgt::slot_cameraZoomLevelChanged(double zoomLevel)
{
	//qDebug() << "slot_zoomLevelChanged:" << zoomLevel;
	Ui.horizontalSlider_Zoom->setValue(zoomLevel);
}

void InvestmentIncomeWgt::slot_HAngleSliderValueChanged(int value)
{
	m_camera->setXRotation(value);
}

void InvestmentIncomeWgt::slot_VAngleSliderValueChanged(int value)
{
	m_camera->setYRotation(value);
}

void InvestmentIncomeWgt::slot_ZoomLevelSliderValueChanged(int value)
{
	m_camera->setZoomLevel(value);
}

void InvestmentIncomeWgt::slot_updateEstimateProgress(const int val)
{
	Ui.progressBar_EstmateState->setValue(val);
}

void InvestmentIncomeWgt::slot_drawCardObjChanged()
{
	
	if (Ui.radioButton_CharacterOnly->isChecked())
	{
		Ui.checkBox_lastGoldCharacterWrong->setEnabled(true);
		Ui.spinBox_charPoolAreadyInTicket->setEnabled(true);
		Ui.checkBox_lastGoldWeaponWrong->setEnabled(false);
		Ui.spinBox_WeaponPoolAreadyInTicket->setEnabled(false);
	}
	else if (Ui.radioButton_WeaponOnly->isChecked())
	{
		Ui.checkBox_lastGoldCharacterWrong->setEnabled(false);
		Ui.spinBox_charPoolAreadyInTicket->setEnabled(false);
		Ui.checkBox_lastGoldWeaponWrong->setEnabled(true);
		Ui.spinBox_WeaponPoolAreadyInTicket->setEnabled(true);
	}
	else if (Ui.radioButton_getAll->isChecked())
	{
		Ui.checkBox_lastGoldCharacterWrong->setEnabled(true);
		Ui.spinBox_charPoolAreadyInTicket->setEnabled(true);
		Ui.checkBox_lastGoldWeaponWrong->setEnabled(true);
		Ui.spinBox_WeaponPoolAreadyInTicket->setEnabled(true);
	}

	if (Ui.radioButton_getAll->isChecked())
	{
		Ui.groupBox_PoolTransformType->setEnabled(true);
		slot_transformTypeChanged();
	}
	else
	{
		Ui.groupBox_PoolTransformType->setEnabled(false);
	}
}
