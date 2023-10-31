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

#ifndef DOUBLE_MATRIX
#define DOUBLE_MATRIX

#include <QVector>
#include <QSize>

//double���󣬷�����ж�ά�������
//�������ʱĬ����Ԫ��ֵΪ0
//������±��������ϰ�ߣ���һ��Ԫ���±�Ϊ0������ζ�����Ͻ�Ԫ�ص��±�Ϊ��0��0����
//�������ĳߴ���3��4�У���ô���½�Ԫ�ص��±�Ϊ��2��3��


class DoubleMatrix
{
public:
	DoubleMatrix(int row = 0, int column = 0);
	DoubleMatrix(QSize size);
	~DoubleMatrix();

	//���ؾ����С,����QSize��height����������width��������
	const QSize getMatrixSize() const { return QSize(m_column, m_row); }
	//���ָ��Ԫ���Ƿ����
	bool		checkElementExist(int row, int column);
	//�����ض�λ�õ�ֵ���������MatrixSize����ô�᷵��-1
	double		getValueAt(int row, int column);
	//�����ض�λ�õ�ֵ�������������MatrixSize�������������֮ǰ���ߴ�
	const double getConstValueAt(int row, int column) const { return m_VecMatrixValue[row][column];};
	//�����ض�λ�õ�ֵ���ã�������Χ���
	double&		getValueRefAt(int row, int column);
	//���þ���һ��λ�õ�ֵ�������������Χ����ô�Զ�������󵽰�����Ԫ����С�ߴ�
	void		setValue(int row, int column,double value);
	//���ž����С����֤�������ź�ĳߴ�������row�к�column��
	//������������/����С�ڵ�ǰ�ߴ磬��ô��/�в����в���
	void		expandMatrix(int row, int column);

	void		expandMatrix(QSize size) { expandMatrix(size.height(),size.width()); };
	//�������
	void		clearMatrix();

private:

	int m_row		= 0;//����������ֵΪ4����ζ��һ����4�У����Ǵ�ʱ�������±���3
	int m_column	= 0;//����������ֵΪ3����ζ��һ����3�У����Ǵ�ʱ�������±���2
	
	//�������������������ϻᱣ֤ÿһ�еĶ�Ӧ�������ǵȳ���
	QVector<QVector<double>> m_VecMatrixValue;

};

#endif