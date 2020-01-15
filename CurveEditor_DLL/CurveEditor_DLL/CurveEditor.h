#pragma once

#include<vector>
#include <string>


namespace CurveEditor
{
	 //CSV����O���t�f�[�^��ǂݍ��݁A�ۑ���f�[�^��ǂݍ��ރN���X
	 class BezierPointList
	 {
	 public:
		 struct Vec2
		 {
			 double x;
			 double y;

			 Vec2()
			 {

			 }
			 Vec2(double x1, double y2)
			 {
				 x = x1;
				 y = y2;
			 }
		 };
		 //3���x�W�F�Ȑ��ɕK�v�ȓ_
		 struct BezierPoint
		 {
			 Vec2 startPoint;     //�J�n�_
			 Vec2 controlPoint1;  //����_1
			 Vec2 controlPoint2;  //����_2
			 Vec2 endPoint;       //�I���_

			 BezierPoint()
			 {

			 }
			 BezierPoint(Vec2 s, Vec2 c1, Vec2 c2, Vec2 e)
			 {
				 startPoint = s;
				 controlPoint1 = c1;
				 controlPoint2 = c2;
				 endPoint = e;
			 }
		 };
	 public:
		 BezierPointList();
		  ~BezierPointList();

		 //CSV����O���t�f�[�^��ǂݍ���
		 // @param Actor�@�ǂݍ���CSV�̃p�X
		 // @return  difference �덷�̋��e�l
		 bool ReadBezierPointList(std::string CSVpath);

		 // �O���t��X����Y�����߂�
		 // @param x�@����0�`1

		 double EvaluateY(double x);

		 //�O���t�f�[�^�Ɉُ�͂Ȃ����H
		 // @return  true �Ȃ琳��
		 bool DateErrorCheck();
	 private:
		 //�����������߂鎞�Ɏg��
		  double Ax;
		  double Ay;
		  double Bx;
		  double By;
		  double Cx;
		  double Cy;

		  std::vector<BezierPoint> m_List;
		  BezierPoint m_SelectPoint;
	 private:
		 BezierPointList(const BezierPointList & cpy);
		 BezierPointList& operator=(const BezierPointList &ope);
		 //�ǂ��̋Ȑ�������
		 // @param x�@����0�`1
		 int SearchBezier(double x);

		 void SetConstants3();
		 // x��^�����t�ɂ��Ă̕����������߂�y��Ԃ�
		 // @param x�@
		 double CalcYfromX(double x);
		 // ����t�ɂ���x�̔����l�����߂�
		 // @param t
		 double sampleCurveDerivativeX(double t);
		 // t����x��y�����߂�
		 Vec2 GetPointAtTime(double t);

		 //�����񂩂琔���ɕϊ����f�[�^��ۑ�
		 void  StringToBezierPoint(std::vector<std::string>& val);

		 //�O���t�f�[�^�̊J��
		 void Release();

	 };
}