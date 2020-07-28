
/////////////////////////////////////
//                                 //
//   �ӿ����������صı���        //
//                                 //
/////////////////////////////////////

#ifndef _hz_objectTypedef_
#define _hz_objectTypedef_


//objectType�Ķ��壨һ��ʶ���ǩ�������໥������
#define TYPE_PEDESTRAIN_                 1   //����
#define TYPE_VEHICLE_                    2   //����
#define TYPE_NOSTDVEHICLE_               4   //�Ǳ공
#define TYPE_FACE_                       8   //����

//pdestrainType�Ķ��壨v3.0�汾��������ʶ���ǩ�������໥�������Ե��ӣ�
#define TYPE_PEDESTRAIN_GLOBAL_          1  //�������ԣ��Ա�+����+�·���ʽ\��ɫ\����+�����+˫���+�����+������+��ɡ+��С��
#define TYPE_PEDESTRAIN_HEAD_            4  //ͷ�����ԣ��۾�+ñ��+ͷ����ɫ�Ϳ�ʽ+������+��绰+����

//vehicleType�Ķ��壨v3.0�汾��������ʶ���ǩ�������໥�������Ե��ӣ�
#define TYPE_VEHICLE_GLOBAL_             1  //����ȫ�����ԣ����͡�Ʒ�ơ�����ɫ��
#define TYPE_VEHICLE_DRIVER_             4  //��ʻԱ���ԣ���ȫ��+��绰����+������+��С��+����+������
#define TYPE_VEHICLE_PLATE_              8  //��������
#define TYPE_VEHICLE_WINDOW_            16  //�������ԣ�v6.5�����������ꡢֽ��С��Ҽ����ڼ���

//noSTdVehicleType�Ķ��壨v3.0�汾��������ʶ���ǩ�������໥�������Ե��ӣ�
#define TYPE_NOSTDVEHICLE_GLOBAL_        1  //�Ǳ�ȫ�����ԣ��Ǳ공��+��ɫ+���˵�
#define TYPE_NOSTDVEHICLE_DRIVER_GLOBAL_ 4  //��ʻԱ���ԣ��Ա�+����+�·���ʽ\��ɫ\����
#define TYPE_NOSTDVEHICLE_DRIVER_HEAD_   8  //�۾�+ñ��+ͷ��+ͷ����ɫ�Ϳ�ʽ+������+��绰+����

//vehiclePlateType (v3.0�汾��������ʶ���ǩ:��������)
#define TYPE_VEHICLE_PLATE_CH_           1  //���ڳ���
#define TYPE_VEHICLE_PLATE_SA_           2  //�Ϸǳ���
#define TYPE_VEHICLE_PLATE_KY_           3  //�����ǳ���
#define TYPE_VEHICLE_PLATE_BZ_           4  //��������

//patternType��v5.5�汾��Ƶ�������߼���0���⣬1�߾��ȣ�
#define PATTERN_EQUALIZE_                0  //����ģʽ��8+4��
#define PATTERN_HIGH_PRECISION_          1  //�߾���ģʽ��8+8��
//#define PATTERN_NO_PROPERTY_             2  //������ģʽ��8+2��

//usageScenarios��v4.1�汾������
#define SCENE_GENERAL_                   0  //ͨ�ó���������+�鿨��
#define SCENE_VIOLATION_                 1  //ͼƬԤ��
#define SCENE_ENTRANCE_                  2  //ͣ���������

//���������������С
#define Max_Num_Batch_                   4   //���������

//����roi��roe
#define HZ_MAX_ROI_NUM_                  1
#define HZ_MAX_ROE_NUM_                  4

//����ͨ��Ŀ����С������v6.5�޸ģ�
#define  Min_Width_Extract_Pedestrain_       28       //��ȡ���˵���С���ؿ��
#define  Min_Width_Extract_NoStdVehicle_     32       //��ȡ�Ǳ공����С���ؿ��
#define  Min_Width_Extract_Vehicle_         108       //��ȡ��������С���ؿ��
#define  Min_Width_Extract_Plate_            32       //��ȡ���Ƶ���С���ؿ��
#define  Min_Width_Extract_Face_             32       //��ȡ��������С���ؿ��
#define  Min_Width_Recognzie_Pedestrain_     64       //ʶ�����˵���С���ؿ��
#define  Min_Width_Recognzie_Vehicle_       160       //ʶ��������С���ؿ��
#define  Min_Width_Recognzie_Driver_         80       //ʶ���ʻԱ����С���ؿ��
#define  Min_Width_Recognzie_Plate_          40       //ʶ���Ƶ���С���ؿ��
#define  Min_Width_Recognzie_Face_           32       //ʶ����������С���ؿ��

//v6.0(ֻ֧������11�ֱ����ʽ)
typedef enum VideoCodec_enum
{
	VideoCodec_MPEG1 = 0,                                       /**<  MPEG1             */
	VideoCodec_MPEG2,                                           /**<  MPEG2             */
	VideoCodec_MPEG4,                                           /**<  MPEG4             */
	VideoCodec_VC1,                                             /**<  VC1               */
	VideoCodec_H264,                                            /**<  H264              */
	VideoCodec_JPEG,                                            /**<  JPEG              */
	VideoCodec_H264_SVC,                                        /**<  H264-SVC          */
	VideoCodec_H264_MVC,                                        /**<  H264-MVC          */
	VideoCodec_HEVC,                                            /**<  HEVC              */
	VideoCodec_VP8,                                             /**<  VP8               */
	VideoCodec_VP9,                                             /**<  VP9               */
	VideoCodec_NumCodecs,                                       /**<  Max codecs        *///֧�ֵĽ�����������
	VideoCodec_NoCodecs,                                        /**<  No  codecs        *///������
}VideoCodec;

//���εĽṹ����
typedef struct
{
	int x;
	int y;
	int width;
	int height;
}objectRect_;
typedef struct
{
	long long timeSt;
	int x;
	int y;
	int width;
	int height;
}objectRectT_;

//all struct size 128  : int[32]
#define   HZ_PARAM_BUF_SIZE_        128
typedef struct
{
	//0.��ͬ�ֶ�: int[2]
	// һ������ѡ��
	int   objectType;              // �ο�objectType����,Ĭ��0ȫѡ
	int   gpuID;                   // Ĭ��0 (ÿ������ֻ��ָ��һ��GPU)
	//����ʶ����ز���: int[3]
	int   pedestrianMinWidth;      // ������Сʶ���ȣ�Ĭ��32��  >=32
	float pedestrianDetectProb;    // ���˼����ֵ��    Ĭ��0.4f  >=0.40f
	float pedestrianPropertyProb;  // ��������ʶ����ֵ��Ĭ��0.3f  >=0.30f
	//����ʶ����ز���: int[4]
	int   vehicleMinWidth;         // ������Сʶ���ȣ�Ĭ��108�� >=108
	float vehicleDetectProb;       // ���������ֵ��Ĭ��0.4f  >=0.40f
	float vehicleRecogProb;        // ����ʶ����ֵ��Ĭ��0.1f  >=0.10f
	float vehiclePropertyProb;     // ��ʻԱ����ʶ����ֵ: Ĭ��0.5f  >=0.50f
	//����ʶ����ز���: int[4]
	int   plateMinWidth;           // ������Сʶ���ȣ�Ĭ��40��>=40
	float plateDetectProb;         // ���Ƽ����ֵ��Ĭ��0.4f  >=0.40f
	float plateRecogProb;          // ����ʶ����ֵ��Ĭ��0.3f  >=0.30f
	char  defaultProvince[4];      // Ĭ��ʡ�ݣ����磺��������ģ������ı�ʡ���ƽ���ᱻ������Ĭ��ʡ�ݣ��Ǳ�ʡ������1/1000���ʻᱻ��������
	//�Ǳ공ʶ����ز���: int[4]
	int   noStdVehicleMinWidth;    // �Ǳ공��Сʶ���ȣ�Ĭ��32��  >=32
	float noStdVehicleDetectProb;  // �Ǳ공�����ֵ��Ĭ��0.4f  >=0.40f
	float noStdVehicleRecogProb;   // �Ǳ공ʶ����ֵ��Ĭ��0.3f  >=0.30f
	float noStdVehiclePropertyProb;// �Ǳ공����ʶ����ֵ��Ĭ��0.3f  >=0.30f
	// ��������ѡ��: int[5]
	int   pedestrianType;           // ����2�����壬  Ĭ��0ȫѡ
	int   vehicleType;              // ����2�����壬  Ĭ��0ȫѡ
	int   noStdVehicleType;         // �Ǳ공2�����壬Ĭ��0ȫѡ
	int   vehiclePlateType;         // ����2�����壬  Ĭ��0�����ڳ��ƣ���1���ڳ���, 2�Ϸǳ��ƣ�3�����ǳ���
	int   patternType;              // ʶ��ģʽ,      Ĭ��0����ģʽ��1�߾���(���˺ͷǱ공��СĿ�������������5%-10%�������ٶ��½�15%-20%)
	int   extractSmallObject;       // ��ȡСĿ�꣬   Ĭ��0����Զ��СĿ�꣨Ŀ�갴������͸������򣺳���ǰ6�����Ǳ공ǰ8��������ǰ10����1������СĿ��
	int   extractFuseObject;        // ģ��Ŀ�꣬     Ĭ��0����ģ��Ŀ�꣨������ȷ�������˻�����������������ͳ�����Ϣ����1������ģ��Ŀ��
	//v4.1����ʹ�ó�����int[1]
	int   usageScenarios;           // ����ʹ�ó����� Ĭ��0������+�鿨Ӧ�ó�������1Υ��ץ�ĳ�������ع�+ǰ�ع���

	// �����ռ�: int[7]
	char  reserved[28];
}hz_objectParameter_;


//v4.5�汾
//hz_pedestrain_ int[186]
typedef struct
{
	//0.�������� int[3]
	int          sex;              //�Ա�
	int          age;              //�����
	int          orient;           //����
	//1.ͷ������ int[4]
	int          hairType;         //ͷ������
	int          hairColor;        //ͷ����ɫ
	int          haveGlass;        //�۾�
	int          haveHat;          //ñ��
	//2.�������� int[3]
	int          coatType;         //���¿�ʽ
	int          coatColor;        //������ɫ
	int          coatText;         //��������v4.5������
	//3.�������� int[2]
	int          trousersType;     //���ӳ���
	int          trousersColor;    //������ɫ
	//4.�������� int[3]
	int          haveHandBag;      //�����
	int          haveSinglePack;   //�����
	int          haveBackPack;     //˫���
	//5.�������� int[6]
	int          haveUmbrella;     //��ɡ
	int          haveSuitcase;     //������
	int          haveBaby;         //��С����v4.2������
	int          haveMask;         //�����֣�v4.2������
	int          haveSmoke;        //���̣�v4.2������
	int          haveCall;         //��绰��v4.2������
	//6.���� int[16]
	objectRect_  headRect;         //ͷ������
	objectRect_  upper;            //�ϰ������꣨v4.5������
	objectRect_  lower;            //�°������꣨v4.5������
	//7.���� int[5]
	objectRect_  face;             //�������꣨v4.5������
	float        faceProb;         //�������ʣ�v4.5������
	//v5.5����
	int          trousersStyle;    //����/ȹ��
	int          glassType;        //��ͨ�۾�/ī��
	int          hairStyle;        //���硢��β���̷�

	//�����ռ�   int[145]
	char         reserved[580];
}hz_pedestrain_;
//hz_vehicle_  int[186]
typedef struct
{
	//0.���� int[26]
	char         vehicleName[64];        //������ʽ������-�ɶ�-2010��......
	float        vehicleProb;            //����
	int          vehicleType;            //���ͣ�С����......
	int          vehicleColor;           //��ɫ
	int          vehicleOrient;          //���򣨳�ͷ/��β��
	int          vehicleTypeSpecial;     //��������
	float        vehicleTypeSpecialProb; //�������͸���
	objectRect_  vehicleHead;            //��ͷ����
	//1.��ʻԱ���� int[28]
	objectRect_  driver[2];           //��ʻԱ����(����/����ʻ)
	int          haveSaftBelt[2];     //��ȫ��
	float        haveSaftBeltProb[2]; //��ȫ������
	int          haveCall[2];         //��绰
	float        haveCallProb[2];     //��绰����
	int          haveVisor[2];        //������	
	int          haveSmoke[2];        //����
	float        haveSmokeProb[2];    //���̸���	
	int          haveBaby[2];         //��С��
	float        haveBabyProb[2];     //��С������
	int          haveMask[2];         //������
	//2.����ʶ���� int[33]
	objectRect_  plateRect;      //��������
	char         plateName[16];  //���ƺ��룺���硰��B88888��
	float        plateProb;      //���Ƹ���
	int          plateColor;     //������ɫ
	int          plateType;      //��������
	objectRect_  plateRect2;     //�������꣨v5.5������
	char         plateName2[16]; //���ƺ��루v5.5������
	float        plateProb2;     //���Ƹ��ʣ�v5.5������
	int          plateColor2;    //������ɫ��v5.5������
	int          plateType2;     //�������ͣ�v5.5������
	objectRect_  plateRect3;     //�������꣨v6.5������
	char         plateName3[16]; //���Ƹ��ʣ�v6.5������
	float        plateProb3;     //���Ƹ��ʣ�v6.5������
	int          plateColor3;    //������ɫ��v6.5������
	int          plateType3;     //�������ͣ�v6.5������
	//4. ��ʻԱ���� int[10]
	objectRect_  driverFace[2];      //��ʻԱ��������(����/����ʻ)��v4.5������
	float        driverFaceProb[2];  //��ʻԱ��������(����/����ʻ)��v4.5������
    //6. �������� int[38] 
	objectRect_  vehicleWindow;   //������v6.5������
	objectRect_  sunRoof;         //�촰��v6.5������
	objectRect_  spareTire;       //��̥��v6.5������
	objectRect_  luggageRack;     //����ܣ�v6.5������
	objectRect_  tissue;          //ֽ��У�v6.5������
	objectRect_  pendant;         //�Ҽ���v6.5������
	objectRect_  decorationRect;  //�ڼ����꣨v6.5������
	int          decorationType;  //�ڼ����ͣ�v6.5������
	objectRect_  annualRect;      //�������꣨v6.5������
	int          annualNum;       //����������v6.5������
	int          annualShape;     //������״��v6.5������
	int          haveSpray;       //�������֣�v6.5������
	int          haveRoadster;    //����������v6.5������
	int          haveHit;         //����ײ�ۣ�v6.5������
	//�����ռ�   int[51]
	char         reserved[204];
}hz_vehicle_;
//hz_noStdVehicle_  int[186]
typedef struct
{
	//0.�Ǳ공  int[8]
	int          noStdVehicleType;    //�Ǳ공����
	float        noStdVehicleProb;    //�Ǳ공����
	int          noStdVehicleColor;   //�Ǳ공��ɫ
	int          noStdVehicleOrient;  //���򣨳�ͷ/��β��
	objectRect_  noStdVehicleHead;
	//1.��ʻԱ���� int[7]
	objectRect_  driver;              //��ʻԱ����
	objectRect_  driverHead;          //��ʻԱͷ�����꣨v4.5������
	int          driverSex;           //�Ա�
	int          driverAge;           //�����
	int          driverTypeSpecial;   //��ʻԱ���ͣ�����˳�ᡢ�������
	//2.ͷ������ int[5]
	int          driverHairType;      //ͷ������
	int          driverHairColor;     //ͷ����ɫ
	int          driverHaveGlass;     //���۾�
	int          driverHaveHat;       //��ñ��
	int          driverHaveHelmet;    //��ͷ��
	//3.�������� int[3]
	int          driverCoatType;      //���¿�ʽ
	int          driverCoatColor;     //������ɫ
	int          driverCoatText;     //��������v4.5������
	//4.������� int[5]
	int          havePassenger;       //���˿�
	int          haveUmbrella;        //��������
	int          haveMask;            //�����֣�v4.2������
	int          haveSmoke;           //���̣�v4.2������
	int          haveCall;            //��绰��v4.2������
	//5.���� int[5]
	objectRect_  driverFace;          //��ʻԱ�������꣨v4.5������
	float        driverFaceProb;      //��ʻԱ�������ʣ�v4.5������
	//v5.5����
	int          passengerNum;        //�˿�������0û�У�1, 2��
	int          tricycleType;        //���ֳ�����
	int          driverGlassType;     //��ͨ�۾�/ī��
	int          driverHairStyle;     //���硢��β���̷�

	//�����ռ� int[145]
	char         reserved[580];
}hz_noStdVehicle_;

//hz_face_  int[186]
typedef struct 
{
	// int[4]
	int			color;			//��ɫ
	int			ethnic;			//����
	int			gender;			//�Ա�
	int			ageGroup;		//�����
	// ��ͷint[1]	
	int			hat;			//ñ��
	
	// ���int[5]
	int			smile;			//΢Ц	
	int			mask;			//����
	int			beard;			//����
	int			expression;		//����
	int			smoke;			//����
	// �۾�int[3]
	int			glass;			// �۾�
	int			lefteye;		// ����״̬
	int			righteye;		// ����״̬
	// 3D�Ƕ�int[3]
	float		yaw;			// ˮƽת����ƫ����
	float		pitch;			// ��ֱת��������
	float		roll;			// ����ת������ת��

	char		reserved[680];		//����
}hz_face_;

#define   HZ_MAX_NUM_RESULT_        16
#define   HZ_MAX_SIZE_RESULT_       768
#define   HZ_MAX_DIM_FEATURE_		512
#define   HZ_MAX_DIM_FEATURE_F_     1024
//hz_objectResult_ int[192]
typedef struct
{
	//ͨ��Ŀ���� int[6]
	int          detectType;     //�ο�objectType
	objectRect_  detectRect;     //����
	float        detectProb;     //����
	//���Խṹ�� int[122]
	union
	{
		hz_pedestrain_   p;
		hz_vehicle_      v;
		hz_noStdVehicle_ n;
		hz_face_		 f;
		char             r[744];
	};
}hz_objectResult_;


//////////////////////////////////////////////////////////
//ͨ��Ŀ���δ֪���壨����vehicleColor����������0����ʾδ֪��
#define Object_Unknow_              0    //δ֪
//����have������Զ�����ͬ������
#define Object_NotHave_             1    //û��
#define Object_Have_                2    //��
//ͨ��Ŀ���Ŀ�곯��
#define Object_Front_               1    //��������ͷ
#define Object_Side_                2    //���������
#define Object_Back_                3    //��������ͷ

//��������ʶ����
// sex���Ա�
#define Pedestrain_Female_           1    //Ů��
#define Pedestrain_Male_             2    //����
// coatColor trousersColor�����ºͿ�����ɫ
#define Pedestrain_Clothes_Black_    1    //��ɫ
#define Pedestrain_Clothes_Blue_     2    //��ɫ
#define Pedestrain_Clothes_Brown_    3    //��ɫ
#define Pedestrain_Clothes_Green_    4    //��ɫ
#define Pedestrain_Clothes_Grey_     5    //��ɫ
#define Pedestrain_Clothes_Orange_   6    //��ɫ
#define Pedestrain_Clothes_Pink_     7    //��ɫ
#define Pedestrain_Clothes_Purple_   8    //��ɫ
#define Pedestrain_Clothes_Red_      9    //��ɫ
#define Pedestrain_Clothes_White_   10    //��ɫ
#define Pedestrain_Clothes_Yellow_  11    //��ɫ
// coatType trousersType�� ���ºͿ��ӳ���
#define Pedestrain_Clothes_Short_    1    //����̿�
#define Pedestrain_Clothes_Long_     2    //���䳤��
// coatText�� �·�����
#define Pedestrain_Clothes_Stripes_  1    //���� v4.5����
#define Pedestrain_Clothes_Lattice_  2    //���� v4.5����
// trousersStyle: ��������
#define Pedestrain_Trousers_Nomal_   1    //���� v5.5����
#define Pedestrain_Trousers_Skirt_   2    //ȹ�� v5.5����

// age�������
#define Pedestrain_Child_            1    //��ͯ
#define Pedestrain_Adult_            2    //����
#define Pedestrain_Older_            3    //����
// hairColor��ͷ����ɫ
#define Pedestrain_Hair_Black_       1    //��ɫ
#define Pedestrain_Hair_White_       2    //��ɫ
#define Pedestrain_Hair_Yellow_      3    //��ɫ
#define Pedestrain_Hair_Red_         4    //��ɫ
// hairType��ͷ������
#define Pedestrain_Hair_Short_       1    //�̷�
#define Pedestrain_Hair_Bald_        2    //��ͷ
#define Pedestrain_Hair_Long_        3    //����
// hairStyle: 
#define Pedestrain_Hair_Shawl_       1    //���� v5.5����
#define Pedestrain_Hair_Ponytail_    2    //��β v5.5����
#define Pedestrain_Hair_Upstyle_     3    //�̷� v5.5����
// glassType��
#define Pedestrain_Glass_Nomal_      1    //��ͨ�۾� v5.5����
#define Pedestrain_Glass_Dark_       2    //ī�� v5.5����

//��������ʶ����
//(1)vehicleType���������Ͷ���
#define Vehicle_Type_SALOON_		 1	  //С����
#define Vehicle_Type_VAN_			 2	  //�����
#define Vehicle_Type_FREIGHT_		 3    //����
#define Vehicle_Type_PASSENGER_	     4    //�ͳ�
#define Vehicle_Type_SUV_	         5    //SUV
#define Vehicle_Type_FREIGHT_BIG_	 6    //�����
#define Vehicle_Type_PASSENGER_BIG_  7    //��ͳ�
//#define Vehicle_Type_NO_STD_         8    //�Ǳ공
#define Vehicle_Type_FREIGHT_SML_	 9    //С���� v4.5����
#define Vehicle_Type_Pickup_        10    //Ƥ��   v4.5����
#define Vehicle_Type_MPV_           11    //MPV    v6.0����
#define Vehicle_Type_OFF_LOAD_      12    //ԽҰ   v6.5����
//(1)vehicleTypeSpecial���������⳵�Ͷ���
#define Vehicle_Type_Normal_		 0 	  //��ͨ����
#define Vehicle_Type_Dangerous_		 1	  //Σ��Ʒ���䳵
#define Vehicle_Type_TAXI_		     2	  //���⳵
#define Vehicle_Type_SchoolBus_      3    //У��
#define Vehicle_Type_PublicBus_      4    //������
#define Vehicle_Type_DumpTruck_      5    //��ͷ��
#define Vehicle_Type_MixerTruck_     6    //���賵
#define Vehicle_Type_GarbageTruck_   7    //�������䳵
#define Vehicle_Type_VanTruck_       8    //��ʽ����
#define Vehicle_Type_PlateTruck_     9    //��ʽ���䳵
#define Vehicle_Type_TankTruck_     10    //�����޳�
#define Vehicle_Type_Trailer_       11    //�ϳ�
#define Vehicle_Type_CanvasTruck_   12    //��ʽ����(����)
#define Vehicle_Type_Ambulance_     13    //�Ȼ���
#define Vehicle_Type_Sprinkler_     14    //��ˮ��
//v5.0��������ɫ�޸ĳɺͷǱ공���·���ɫӳ�����һ�� (���߰汾)
#define Vehicle_Color_Black_         1    //��ɫ
#define Vehicle_Color_Blue_          2    //��ɫ
#define Vehicle_Color_Brown_         3    //��ɫ
#define Vehicle_Color_Green_         4    //��ɫ
#define Vehicle_Color_Grey_          5    //��ɫ
#define Vehicle_Color_Orange_        6    //��ɫ
#define Vehicle_Color_Pink_          7    //��ɫ
#define Vehicle_Color_Purple_        8    //��ɫ
#define Vehicle_Color_Red_           9    //��ɫ
#define Vehicle_Color_White_        10    //��ɫ
#define Vehicle_Color_Yellow_       11    //��ɫ
//(3) plateColor��������ɫ����
#define Plate_Color_BLUE_            1  //��ɫ
#define Plate_Color_YELLOW_          2  //��ɫ
#define Plate_Color_WHITE_           3  //��ɫ
#define Plate_Color_BLACK_           4  //��ɫ
#define Plate_Color_GREEN_           5  //��ɫ������Դ��
#define Plate_Color_RED_	         6  //��ɫ�����⳵�ƣ�
#define Plate_Color_GRAY_	         7  //��ɫ�����⳵�ƣ�
#define Plate_Color_PURPLE_	         8  //��ɫ�����⳵�ƣ�
#define Plate_Color_YELLOW_GREEN_    9  //����ɫ������Դ��
//��4��plateType���������Ͷ���
#define Plate_Type_BLUE_             1   //����С����
#define Plate_Type_BLACK_            2   //���ź���
#define Plate_Type_YELLOW_           3   //���Ż���
#define Plate_Type_YELLOW2_          4   //˫�Ż���
#define Plate_Type_POLICE_           5   //��������
#define Plate_Type_ARMPOL_           6   //�����侯����
#define Plate_Type_ARMPOL2_          7   //˫���侯����
#define Plate_Type_ARMY_             8   //���ž�����
#define Plate_Type_ARMY2_            9   //˫�ž�����
#define Plate_Type_EMBASSY_         10   //ʹ�ݳ���
#define Plate_Type_HONGKONG_        11   //��۳���
#define Plate_Type_TRACTOR_         12   //ũ�ó���
#define Plate_Type_MACAU_           13   //���ų���
#define Plate_Type_LINGGUAN_        16   //�������
#define Plate_Type_CIVIL_           17   //�񺽳���
#define Plate_Type_BLACK2_          18   //˫�ź���
#define Plate_Type_GUACHE_          27   //�ҳ�
#define Plate_Type_COACH_	        28   //��������
#define Plate_Type_NEW_	            30   //����Դ����
#define Plate_Type_TEMP_            31   //v6.5��������ʱ����
#define Plate_Type_NO_	            32   //v4.0�������޳���
#define Plate_Type_DEFACE_	        33   //v4.5������������
#define Plate_Type_SHIELD_	        34   //v4.5�������ڵ�����
#define Plate_Type_ENGLISH_         35   //v4.5���������⳵��
//////////////////////////////////////////////////////////
//vehicle window���
//annualShape �����������״
#define Vehicle_AnnualShape_Block_         1  //v6.5��������״�ֲ�
#define Vehicle_AnnualShape_Widthwise_     2  //v6.5����������ֲ�
#define Vehicle_AnnualShape_Longitudinal_  3  //v6.5����������ֲ�
//decorationType �ڼ�����
#define Vehicle_DcorationType_Statue_      1  //v6.6����������
#define Vehicle_DcorationType_Doll_        2  //v6.6��������ż
#define Vehicle_DcorationType_Bottle_      3  //v6.6������ˮƿ
#define Vehicle_DcorationType_Deodorizer_  4  //v6.6���������¼�
#define Vehicle_DcorationType_Flag_        5  //v6.6����������

// �Ǳ공���Զ���(���������Ʊ�ǩ�Ķ���һ��)
// driverSex���Ա�
#define NoStdVehiclDriver_Female_           1    //Ů��
#define NoStdVehiclDriver_Male_             2    //����
// noStdVehicleColor���Ǳ공��ɫ
#define NoStdVehiclColor_Black_       1    //��ɫ
#define NoStdVehiclColor_Blue_        2    //��ɫ
#define NoStdVehiclColor_Brown_       3    //��ɫ
#define NoStdVehiclColor_Green_       4    //��ɫ
#define NoStdVehiclColor_Grey_        5    //��ɫ
#define NoStdVehiclColor_Orange_      6    //��ɫ
#define NoStdVehiclColor_Pink_        7    //��ɫ
#define NoStdVehiclColor_Purple_      8    //��ɫ
#define NoStdVehiclColor_Red_         9    //��ɫ
#define NoStdVehiclColor_White_      10    //��ɫ
#define NoStdVehiclColor_Yellow_     11    //��ɫ
// driverCoatColor����������ɫ
#define NoStdVehiclDriver_Clothes_Black_    1    //��ɫ
#define NoStdVehiclDriver_Clothes_Blue_     2    //��ɫ
#define NoStdVehiclDriver_Clothes_Brown_    3    //��ɫ
#define NoStdVehiclDriver_Clothes_Green_    4    //��ɫ
#define NoStdVehiclDriver_Clothes_Grey_     5    //��ɫ
#define NoStdVehiclDriver_Clothes_Orange_   6    //��ɫ
#define NoStdVehiclDriver_Clothes_Pink_     7    //��ɫ
#define NoStdVehiclDriver_Clothes_Purple_   8    //��ɫ
#define NoStdVehiclDriver_Clothes_Red_      9    //��ɫ
#define NoStdVehiclDriver_Clothes_White_   10    //��ɫ
#define NoStdVehiclDriver_Clothes_Yellow_  11    //��ɫ
// driverCoatType�����³���
#define NoStdVehiclDriver_Clothes_Short_    1    //����̿�
#define NoStdVehiclDriver_Clothes_Long_     2    //���䳤��
// driverCoatText���·�����
#define NoStdVehiclDriver_Clothes_Stripes_  1    //���� v4.5����
#define NoStdVehiclDriver_Clothes_Lattice_  2    //���� v4.5����
// driverAge�������
#define NoStdVehiclDriver_Child_            1    //��ͯ
#define NoStdVehiclDriver_Adult_            2    //����
#define NoStdVehiclDriver_Older_            3    //����
// dirverHairColor��ͷ����ɫ
#define NoStdVehiclDriver_Hair_Black_       1    //��ɫ
#define NoStdVehiclDriver_Hair_White_       2    //��ɫ
#define NoStdVehiclDriver_Hair_Yellow_      3    //��ɫ
#define NoStdVehiclDriver_Hair_Red_         4    //��ɫ
// dirverHairType��ͷ������
#define NoStdVehiclDriver_Hair_Short_       1    //�̷�
#define NoStdVehiclDriver_Hair_Bald_        2    //��ͷ
#define NoStdVehiclDriver_Hair_Long_        3    //����
// hairStyle: 
#define NoStdVehiclDriver_Hair_Shawl_       1    //���� v5.5����
#define NoStdVehiclDriver_Hair_Ponytail_    2    //��β v5.5����
#define NoStdVehiclDriver_Hair_Upstyle_     3    //�̷� v5.5����
// DeriverGlassType��
#define NoStdVehiclDriver_Glass_Nomal_      1    //��ͨ�۾� v5.5����
#define NoStdVehiclDriver_Glass_Dark_       2    //ī�� v5.5����

//noStdVehicleType���Ǳ공����ʶ����
#define NoStdVehicle_BatteryBike_           1    //�綯���г�
#define NoStdVehicle_BatteryMotor_          2    //�綯Ħ�г�
#define NoStdVehicle_Bike_                  3    //���г�
#define NoStdVehicle_Motor_                 4    //Ħ�г�
#define NoStdVehicle_MotorLight_            5    //����Ħ�г�
#define NoStdVehicle_Tricycle_              6    //���ֳ�
//driverTypeSpecial
#define NoStdVehiclDriver_SF_               1    //˳�� v4.2����
#define NoStdVehiclDriver_Cavalry_          2    //�������� v5.5����

//TricycleType
#define NoStdVehicl_Tricycle_Hopper_        1    //��ʽ���ֳ� v5.5����
#define NoStdVehicl_Tricycle_Shed_          2    //��ʽ���ֳ� v5.5����
#define NoStdVehicl_Tricycle_Box_           3    //��ʽ���ֳ� v5.5����
//////////////////////////////////////////////////////////

//��ͼ��ͼ������ز���
#define  HZ_MAX_DIM_STRING_     64
#define  HZ_MAX_LOCAL_NUM_       6
#define  Retrival_Threshold_   0.5f         //Ĭ�ϵĹ�����ֵ
#define  Retrival_Def_Near_    64           //Ĭ��ֵ�������
#define  Retrival_Max_Near_    1024         //�������Ľ������
#define  Retrival_Max_Batch_  (1024*1024)   //���batch����lM
// ����64�ֽ�
typedef struct hz_objectRetrivalParameter_
{
	float   Threshold;       //������ֵ��>=0.5f
	int     nNear;           //������ǰN����Ĭ��ֵ64
	// �����ռ�
	char  reserved[56];
}hz_objectRetrivalParameter_;


////////////////////////////////////////////////////////////////////////////////////////////
//��ع�+ǰ�ع�����(V4.1���ֻ��ˣ���Ӧֵ����)
#define Data_Negative_                      0   //��Ƭ
#define Data_Postive_                       1   //��Ƭ
#define Data_Exception_                     2   //�쳣
//��ع�+ǰ�ع����ط�Ƭԭ��
#define Return_Postive_                     0   // ��Ƭ
#define Return_Negative_                    1   // ��Ƭ
#define Return_ObjectNoPlate_               2   // δ���ҳ���
#define Return_PlateTrajIncomp_             3   // ���ƹ켣������
#define Return_PlateNoClear_                4   // ���Ʋ�����
#define Return_PlateError_                  5   // ����ʶ�����
#define Return_SpecialVehicle_              6   // ���⳵��
#define Return_TruckRule_                   7   // �������������д�������
#define Return_RoadRule_                    8   // �����㲻������ʻ��������
#define Return_ForeignPlate_                9   // ���������⴦������
#define Return_HaveSaftBelt0_              10   // ����������ʻ��ȫ����������
#define Return_HaveSaftBelt1_              11   // �����㸱��ʻ��ȫ����������
#define Return_NoHaveCall0_                12   // ����������ʻ��绰��������
#define Return_NoHaveBaby1_                13   // �����㸱��ʻ��С����������
#define Return_NoHaveSmoke0_               14   // ����������ʻ���̴�������
#define Return_LineRule_                   15   //  �������ֹ���߹���
//v4.5����
#define Return_CrossWalkRule_              16   // ���������е�ͣ�����д�������
#define Return_SpeedingRule_               17   // �����㳬�ٴ�������
#define Return_LaneGuide_                  18   // �����㲻���������򴦷�����
#define Return_RunRedLights_               19   // �����㴳��ƴ�������
#define Return_IntersectionParking_        20   // ������·��ͣ����������
//v5.5����
#define Return_Retrograde_                 21   // ���������д�������
#define Return_YellowGridIllegalParking_   22   // �����������Υ��ͣ������
#define Return_IllegalParing_              23   // ������Υ��ͣ������
//��Ƭ��ԭ��
//v5.0����
#define subReturn_Ambulance_                  33   // �Ȼ��������ɼ�
#define subReturn_Police_                     34   // �����������ɼ�
#define subReturn_Army_                       35   // �����������ɼ�
#define subReturn_Trailer_                    36   // ��Ԯ�������ϳ������ɼ�
#define subReturn_Tractor_                    37   // ũ�ó������ɼ�
#define subReturn_Sprinkler_                  38   // ��ˮ�������ɼ�
#define subReturn_ShiLing_                    39   // ʹ��ݳ������ɼ�
//v5.5����
#define subReturn_Missing_image               40   // ͼƬ�ɼ���ȫ
#define subReturn_StopLineNotClear            41   // ����ֹͣ�߲�����
#define subReturn_LaneNotClear                42   // �����ֹ���߲�����
#define subReturn_FrontWheelPassedStopLine    43   // ����ǰ���ѹ�ֹͣ�ߣ�ͼ1��
#define subReturn_RearWheelNotPassedStopLine  44   // ��������δ��ֹͣ�ߣ�ͼ3��
//��ֹ����
#define subReturn_SinglesidedPressureLine     45   // ��������ѹ��ֹ����
#define subReturn_NoPressureLine              46   // ����δѹ��ֹ����
//��������
#define subReturn_NotPedestrian               47   // ����δ�ڰ�������
//�����
#define subReturn_NotAllRedLights             48   //�źŵ�״̬�쳣
//���������ͷ
#define subReturn_ArrorNotClear               49   //���浼���־������


//////////////////////////////////////////////
//��Ƭ�ع�����ع�������ѡ��(V4.1���ֻ��ˣ���Ӧֵ����)
#define RollType_ForeignPlate_			    1    // ��س�
#define RollType_PlateNoExist_				2    // �޳���
#define RollType_PlateNoClear_		        3    // ���ƺ���ģ��
#define RollType_PlateError_		        4    // ����ʶ�����
#define RollType_TruckRule_	                5    // ���������
#define RollType_RoadRule_		            6    // ��������ʻ
//��Ƭ�ع�����ع��������ṹ
typedef struct
{
	int  nRecycleType;							 // ��ع�����ѡ��
	char pProvince[8];							 // Ĭ�ϵ����� �硰��B��
	int  nMatchPattern;							 // ����ƥ��ģʽ��0��ȷƥ�䣬1ģ��ƥ�䣩
	int  nMatchNumber;							 // ģ��ƥ���ַ�����>=4��
	char pInfoPlateNames[16];                    // ץ�ĳ��ƺ���
	int  nInfoLane;                              // ������
	char reserved[160];
}hz_InputParameter;


//////////////////////////////////////////////
//ͼƬԤ��ǰ�ع�������ѡ��19���жϹ���,������ӣ�
#define PretrialType_ObjectNoPlate_                      1  // δ���ҳ���
#define PretrialType_PlateNoClear_                       2  // ���Ʋ�����
#define PretrialType_PlateTrajIncomp_                    4  // ���ƹ켣������(ͼƬ�ɼ���ȫ)
#define PretrialType_PlateError_                         8  // ����ʶ�����
//#define PretrialType_SpecialVehicle_                  16  // ���⳵�ͣ����ã�����˶�����
#define PretrialType_TruckRule_                         32  // ��������д�������
#define PretrialType_RoadRule_                          64  // ��������ʻ��������
#define PretrialType_ForeignPlate_                     128  // ���⴦������
#define PretrialType_HaveSaftBelt0_                    256  // ���ݰ�ȫ����������
#define PretrialType_HaveSaftBelt1_                    512  // ���ݰ�ȫ����������
#define PretrialType_NoHaveCall0_                     1024  // ���ݴ�绰��������
#define PretrialType_NoHaveBaby1_                     2048  // ���ݱ�С����������
#define PretrialType_NoHaveSmoke0_                    4096  // ���ݳ��̴�������
#define PretrialType_LineRule_                        8192  // ��ֹ���߹���
//v4.5����
#define PretrialType_CrossWalkRule_                  16384  // ���е�ͣ�����й���
#define PretrialType_SpeedingRule_                   32768  // ���ٹ���
#define PretrialType_LaneGuide_                      65536  // �����������
#define PretrialType_RunRedLights_                  131072  // ����ƹ���
#define PretrialType_IntersectionParking_           262144  // ·��ͣ������
//v5.5����
#define PretrialType_Retrograde_                    524288  // ���й���
#define PretrialType_YellowGridIllegalParking_     1048576  // ������Υ��ͣ������
#define PretrialType_IllegalParing_                2097152  // Υ��ͣ�����򣨽�ֹͣ����־��

//20190326���⳵��ϸ�ֹ�������(������ӣ�
#define PretrialType_Ambulance_                   1  // �Ȼ��������ɼ�����
#define PretrialType_Police_                      2  // �����������ɼ�����
#define PretrialType_Army_                        4  // �����������ɼ�����
#define PretrialType_Trailer_                     8  // ��Ԯ�����ϳ����������ɼ�����
#define PretrialType_Tractor_                    16  // ũ�ó������ɼ�����
#define PretrialType_Sprinkler_                  32  // ��ˮ�������ɼ�����
#define PretrialType_ShiLing_                    64  // ʹ��ݳ������ɼ�����

//ͼƬԤ��ǰ�ع��������ṹ
//hz_pretrialParameter
typedef struct
{
	int   nPretrialType;					     // ǰ�ع�����ѡ��
	char  pProvince[8];							 // Ĭ�ϵ����� �硰��B��
	char  pInfoPlateNames[16];                   // ��ȡ���ĳ�����Ϣ
	int   nInfoLane;                             // ������
	int   nPretrialType_Special;                 // ���⳵��(�����ϸ������)   20190326����
	char  reserved[220];
}hz_pretrialParameter;
////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _WIN64
#define __declspec(dllexport)  __attribute__((visibility("default")))
#endif

#endif // !hz_objectTypedef_
