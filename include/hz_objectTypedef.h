
/////////////////////////////////////
//                                 //
//   接口输入输出相关的变量        //
//                                 //
/////////////////////////////////////

#ifndef _hz_objectTypedef_
#define _hz_objectTypedef_


//objectType的定义（一级识别标签：属性相互独立）
#define TYPE_PEDESTRAIN_                 1   //行人
#define TYPE_VEHICLE_                    2   //车辆
#define TYPE_NOSTDVEHICLE_               4   //非标车
#define TYPE_FACE_                       8   //人脸

//pdestrainType的定义（v3.0版本新增二级识别标签：属性相互独立可以叠加）
#define TYPE_PEDESTRAIN_GLOBAL_          1  //整体属性：性别+年龄+衣服款式\颜色\纹理+单肩包+双肩包+手提包+拉杆箱+打伞+抱小孩
#define TYPE_PEDESTRAIN_HEAD_            4  //头部属性：眼镜+帽子+头发颜色和款式+戴口罩+打电话+抽烟

//vehicleType的定义（v3.0版本新增二级识别标签：属性相互独立可以叠加）
#define TYPE_VEHICLE_GLOBAL_             1  //车辆全局属性：车型、品牌、年款、颜色等
#define TYPE_VEHICLE_DRIVER_             4  //驾驶员属性：安全带+打电话手势+遮阳板+抱小孩+抽烟+戴口罩
#define TYPE_VEHICLE_PLATE_              8  //车牌属性
#define TYPE_VEHICLE_WINDOW_            16  //车窗属性（v6.5新增）：年检标、纸巾盒、挂件、摆件等

//noSTdVehicleType的定义（v3.0版本新增二级识别标签：属性相互独立可以叠加）
#define TYPE_NOSTDVEHICLE_GLOBAL_        1  //非标全局属性：非标车型+颜色+载人等
#define TYPE_NOSTDVEHICLE_DRIVER_GLOBAL_ 4  //驾驶员属性：性别+年龄+衣服款式\颜色\纹理
#define TYPE_NOSTDVEHICLE_DRIVER_HEAD_   8  //眼镜+帽子+头盔+头发颜色和款式+戴口罩+打电话+抽烟

//vehiclePlateType (v3.0版本新增三级识别标签:车牌类型)
#define TYPE_VEHICLE_PLATE_CH_           1  //国内车牌
#define TYPE_VEHICLE_PLATE_SA_           2  //南非车牌
#define TYPE_VEHICLE_PLATE_KY_           3  //肯尼亚车牌
#define TYPE_VEHICLE_PLATE_BZ_           4  //巴西车牌

//patternType（v5.5版本视频流处理逻辑，0均衡，1高精度）
#define PATTERN_EQUALIZE_                0  //均衡模式（8+4）
#define PATTERN_HIGH_PRECISION_          1  //高精度模式（8+8）
//#define PATTERN_NO_PROPERTY_             2  //高性能模式（8+2）

//usageScenarios（v4.1版本新增）
#define SCENE_GENERAL_                   0  //通用场景（卡口+虚卡）
#define SCENE_VIOLATION_                 1  //图片预审
#define SCENE_ENTRANCE_                  2  //停车场出入口

//定义输入批处理大小
#define Max_Num_Batch_                   4   //最大并行数量

//定义roi和roe
#define HZ_MAX_ROI_NUM_                  1
#define HZ_MAX_ROE_NUM_                  4

//定义通用目标最小参数（v6.5修改）
#define  Min_Width_Extract_Pedestrain_       28       //提取行人的最小像素宽度
#define  Min_Width_Extract_NoStdVehicle_     32       //提取非标车的最小像素宽度
#define  Min_Width_Extract_Vehicle_         108       //提取车辆的最小像素宽度
#define  Min_Width_Extract_Plate_            32       //提取车牌的最小像素宽度
#define  Min_Width_Extract_Face_             32       //提取人脸的最小像素宽度
#define  Min_Width_Recognzie_Pedestrain_     64       //识别行人的最小像素宽度
#define  Min_Width_Recognzie_Vehicle_       160       //识别车辆的最小像素宽度
#define  Min_Width_Recognzie_Driver_         80       //识别驾驶员的最小像素宽度
#define  Min_Width_Recognzie_Plate_          40       //识别车牌的最小像素宽度
#define  Min_Width_Recognzie_Face_           32       //识别人脸的最小像素宽度

//v6.0(只支持以下11种编码格式)
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
	VideoCodec_NumCodecs,                                       /**<  Max codecs        *///支持的解码类型总量
	VideoCodec_NoCodecs,                                        /**<  No  codecs        *///不解码
}VideoCodec;

//矩形的结构定义
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
	//0.共同字段: int[2]
	// 一级功能选项
	int   objectType;              // 参考objectType定义,默认0全选
	int   gpuID;                   // 默认0 (每个进程只能指定一个GPU)
	//行人识别相关参数: int[3]
	int   pedestrianMinWidth;      // 行人最小识别宽度：默认32，  >=32
	float pedestrianDetectProb;    // 行人检测阈值，    默认0.4f  >=0.40f
	float pedestrianPropertyProb;  // 行人属性识别阈值：默认0.3f  >=0.30f
	//车辆识别相关参数: int[4]
	int   vehicleMinWidth;         // 车辆最小识别宽度：默认108， >=108
	float vehicleDetectProb;       // 车辆检测阈值：默认0.4f  >=0.40f
	float vehicleRecogProb;        // 车型识别阈值：默认0.1f  >=0.10f
	float vehiclePropertyProb;     // 驾驶员属性识别阈值: 默认0.5f  >=0.50f
	//车牌识别相关参数: int[4]
	int   plateMinWidth;           // 车牌最小识别宽度：默认40，>=40
	float plateDetectProb;         // 车牌检测阈值：默认0.4f  >=0.40f
	float plateRecogProb;          // 车牌识别阈值：默认0.3f  >=0.30f
	char  defaultProvince[4];      // 默认省份，例如：“粤”：模糊不清的本省车牌结果会被修正成默认省份，非本省车牌有1/1000概率会被错误修正
	//非标车识别相关参数: int[4]
	int   noStdVehicleMinWidth;    // 非标车最小识别宽度：默认32，  >=32
	float noStdVehicleDetectProb;  // 非标车检测阈值：默认0.4f  >=0.40f
	float noStdVehicleRecogProb;   // 非标车识别阈值：默认0.3f  >=0.30f
	float noStdVehiclePropertyProb;// 非标车属性识别阈值：默认0.3f  >=0.30f
	// 二级功能选项: int[5]
	int   pedestrianType;           // 行人2级定义，  默认0全选
	int   vehicleType;              // 车辆2级定义，  默认0全选
	int   noStdVehicleType;         // 非标车2级定义，默认0全选
	int   vehiclePlateType;         // 车牌2级定义，  默认0（国内车牌），1国内车牌, 2南非车牌，3肯尼亚车牌
	int   patternType;              // 识别模式,      默认0均衡模式，1高精度(行人和非标车的小目标对象检出率提升5%-10%，处理速度下降15%-20%)
	int   extractSmallObject;       // 提取小目标，   默认0过滤远景小目标（目标按照面积和概率排序：车辆前6个，非标车前8个，行人前10），1不过滤小目标
	int   extractFuseObject;        // 模糊目标，     默认0过滤模糊目标（不能明确看清行人基本特征，车辆车标和车牌信息），1不过滤模糊目标
	//v4.1新增使用场景：int[1]
	int   usageScenarios;           // 设置使用场景， 默认0（卡口+虚卡应用场景），1违规抓拍场景（后回滚+前回滚）

	// 保留空间: int[7]
	char  reserved[28];
}hz_objectParameter_;


//v4.5版本
//hz_pedestrain_ int[186]
typedef struct
{
	//0.整体特征 int[3]
	int          sex;              //性别
	int          age;              //年龄段
	int          orient;           //朝向
	//1.头部属性 int[4]
	int          hairType;         //头发长短
	int          hairColor;        //头发颜色
	int          haveGlass;        //眼镜
	int          haveHat;          //帽子
	//2.上衣属性 int[3]
	int          coatType;         //上衣款式
	int          coatColor;        //上衣颜色
	int          coatText;         //上衣纹理（v4.5新增）
	//3.裤子属性 int[2]
	int          trousersType;     //裤子长短
	int          trousersColor;    //裤子颜色
	//4.背包属性 int[3]
	int          haveHandBag;      //手提包
	int          haveSinglePack;   //单肩包
	int          haveBackPack;     //双肩包
	//5.动作属性 int[6]
	int          haveUmbrella;     //打伞
	int          haveSuitcase;     //拉杆箱
	int          haveBaby;         //抱小孩（v4.2新增）
	int          haveMask;         //戴口罩（v4.2新增）
	int          haveSmoke;        //抽烟（v4.2新增）
	int          haveCall;         //打电话（v4.2新增）
	//6.坐标 int[16]
	objectRect_  headRect;         //头部坐标
	objectRect_  upper;            //上半身坐标（v4.5新增）
	objectRect_  lower;            //下半身坐标（v4.5新增）
	//7.人脸 int[5]
	objectRect_  face;             //脸部坐标（v4.5新增）
	float        faceProb;         //脸部概率（v4.5新增）
	//v5.5新增
	int          trousersStyle;    //裤子/裙子
	int          glassType;        //普通眼镜/墨镜
	int          hairStyle;        //披肩、马尾、盘发

	//保留空间   int[145]
	char         reserved[580];
}hz_pedestrain_;
//hz_vehicle_  int[186]
typedef struct
{
	//0.车型 int[26]
	char         vehicleName[64];        //车辆款式：本田-飞度-2010款......
	float        vehicleProb;            //概率
	int          vehicleType;            //类型：小汽车......
	int          vehicleColor;           //颜色
	int          vehicleOrient;          //朝向（车头/车尾）
	int          vehicleTypeSpecial;     //特殊类型
	float        vehicleTypeSpecialProb; //特殊类型概率
	objectRect_  vehicleHead;            //车头坐标
	//1.驾驶员特征 int[28]
	objectRect_  driver[2];           //驾驶员坐标(主驾/副驾驶)
	int          haveSaftBelt[2];     //安全带
	float        haveSaftBeltProb[2]; //安全带概率
	int          haveCall[2];         //打电话
	float        haveCallProb[2];     //打电话概率
	int          haveVisor[2];        //遮阳板	
	int          haveSmoke[2];        //抽烟
	float        haveSmokeProb[2];    //抽烟概率	
	int          haveBaby[2];         //抱小孩
	float        haveBabyProb[2];     //抱小孩概率
	int          haveMask[2];         //戴口罩
	//2.车牌识别结果 int[33]
	objectRect_  plateRect;      //车牌坐标
	char         plateName[16];  //车牌号码：例如“粤B88888”
	float        plateProb;      //车牌概率
	int          plateColor;     //车牌颜色
	int          plateType;      //车牌类型
	objectRect_  plateRect2;     //车牌坐标（v5.5新增）
	char         plateName2[16]; //车牌号码（v5.5新增）
	float        plateProb2;     //车牌概率（v5.5新增）
	int          plateColor2;    //车牌颜色（v5.5新增）
	int          plateType2;     //车牌类型（v5.5新增）
	objectRect_  plateRect3;     //车牌坐标（v6.5新增）
	char         plateName3[16]; //车牌概率（v6.5新增）
	float        plateProb3;     //车牌概率（v6.5新增）
	int          plateColor3;    //车牌颜色（v6.5新增）
	int          plateType3;     //车牌类型（v6.5新增）
	//4. 驾驶员人脸 int[10]
	objectRect_  driverFace[2];      //驾驶员脸部坐标(主驾/副驾驶)（v4.5新增）
	float        driverFaceProb[2];  //驾驶员脸部概率(主驾/副驾驶)（v4.5新增）
    //6. 车辆解析 int[38] 
	objectRect_  vehicleWindow;   //车窗（v6.5新增）
	objectRect_  sunRoof;         //天窗（v6.5新增）
	objectRect_  spareTire;       //备胎（v6.5新增）
	objectRect_  luggageRack;     //行李架（v6.5新增）
	objectRect_  tissue;          //纸巾盒（v6.5新增）
	objectRect_  pendant;         //挂件（v6.5新增）
	objectRect_  decorationRect;  //摆件坐标（v6.5新增）
	int          decorationType;  //摆件类型（v6.5新增）
	objectRect_  annualRect;      //年检标坐标（v6.5新增）
	int          annualNum;       //年检标数量（v6.5新增）
	int          annualShape;     //年检标形状（v6.5新增）
	int          haveSpray;       //车身喷字（v6.5新增）
	int          haveRoadster;    //敞蓬汽车（v6.5新增）
	int          haveHit;         //车身撞痕（v6.5新增）
	//保留空间   int[51]
	char         reserved[204];
}hz_vehicle_;
//hz_noStdVehicle_  int[186]
typedef struct
{
	//0.非标车  int[8]
	int          noStdVehicleType;    //非标车类型
	float        noStdVehicleProb;    //非标车概率
	int          noStdVehicleColor;   //非标车颜色
	int          noStdVehicleOrient;  //朝向（车头/车尾）
	objectRect_  noStdVehicleHead;
	//1.驾驶员特征 int[7]
	objectRect_  driver;              //驾驶员坐标
	objectRect_  driverHead;          //驾驶员头部坐标（v4.5新增）
	int          driverSex;           //性别
	int          driverAge;           //年龄段
	int          driverTypeSpecial;   //驾驶员类型（例如顺丰、交警铁骑）
	//2.头发属性 int[5]
	int          driverHairType;      //头发长短
	int          driverHairColor;     //头发颜色
	int          driverHaveGlass;     //戴眼镜
	int          driverHaveHat;       //戴帽子
	int          driverHaveHelmet;    //戴头盔
	//3.上衣属性 int[3]
	int          driverCoatType;      //上衣款式
	int          driverCoatColor;     //上衣颜色
	int          driverCoatText;     //上衣纹理（v4.5新增）
	//4.组合特征 int[5]
	int          havePassenger;       //带乘客
	int          haveUmbrella;        //带挡雨棚
	int          haveMask;            //戴口罩（v4.2新增）
	int          haveSmoke;           //抽烟（v4.2新增）
	int          haveCall;            //打电话（v4.2新增）
	//5.坐标 int[5]
	objectRect_  driverFace;          //驾驶员脸部坐标（v4.5新增）
	float        driverFaceProb;      //驾驶员脸部概率（v4.5新增）
	//v5.5新增
	int          passengerNum;        //乘客数量（0没有，1, 2）
	int          tricycleType;        //三轮车类型
	int          driverGlassType;     //普通眼镜/墨镜
	int          driverHairStyle;     //披肩、马尾、盘发

	//保留空间 int[145]
	char         reserved[580];
}hz_noStdVehicle_;

//hz_face_  int[186]
typedef struct 
{
	// int[4]
	int			color;			//肤色
	int			ethnic;			//民族
	int			gender;			//性别
	int			ageGroup;		//年龄段
	// 额头int[1]	
	int			hat;			//帽子
	
	// 嘴巴int[5]
	int			smile;			//微笑	
	int			mask;			//口罩
	int			beard;			//胡须
	int			expression;		//表情
	int			smoke;			//抽烟
	// 眼睛int[3]
	int			glass;			// 眼镜
	int			lefteye;		// 左眼状态
	int			righteye;		// 右眼状态
	// 3D角度int[3]
	float		yaw;			// 水平转动的偏航角
	float		pitch;			// 垂直转动仰俯角
	float		roll;			// 左右转动的旋转角

	char		reserved[680];		//保留
}hz_face_;

#define   HZ_MAX_NUM_RESULT_        16
#define   HZ_MAX_SIZE_RESULT_       768
#define   HZ_MAX_DIM_FEATURE_		512
#define   HZ_MAX_DIM_FEATURE_F_     1024
//hz_objectResult_ int[192]
typedef struct
{
	//通用目标检测 int[6]
	int          detectType;     //参考objectType
	objectRect_  detectRect;     //坐标
	float        detectProb;     //概率
	//属性结构体 int[122]
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
//通用目标的未知定义（除了vehicleColor，其他属性0均表示未知）
#define Object_Unknow_              0    //未知
//所有have类的属性都采用同样定义
#define Object_NotHave_             1    //没有
#define Object_Have_                2    //有
//通用目标的目标朝向
#define Object_Front_               1    //面向摄像头
#define Object_Side_                2    //侧向摄像机
#define Object_Back_                3    //背向摄像头

//行人属性识别定义
// sex：性别
#define Pedestrain_Female_           1    //女性
#define Pedestrain_Male_             2    //男性
// coatColor trousersColor：上衣和裤子颜色
#define Pedestrain_Clothes_Black_    1    //黑色
#define Pedestrain_Clothes_Blue_     2    //蓝色
#define Pedestrain_Clothes_Brown_    3    //棕色
#define Pedestrain_Clothes_Green_    4    //绿色
#define Pedestrain_Clothes_Grey_     5    //灰色
#define Pedestrain_Clothes_Orange_   6    //橙色
#define Pedestrain_Clothes_Pink_     7    //粉色
#define Pedestrain_Clothes_Purple_   8    //紫色
#define Pedestrain_Clothes_Red_      9    //红色
#define Pedestrain_Clothes_White_   10    //白色
#define Pedestrain_Clothes_Yellow_  11    //黄色
// coatType trousersType： 上衣和裤子长短
#define Pedestrain_Clothes_Short_    1    //短袖短裤
#define Pedestrain_Clothes_Long_     2    //长袖长裤
// coatText： 衣服纹理
#define Pedestrain_Clothes_Stripes_  1    //条纹 v4.5新增
#define Pedestrain_Clothes_Lattice_  2    //格子 v4.5新增
// trousersStyle: 下身类型
#define Pedestrain_Trousers_Nomal_   1    //裤子 v5.5新增
#define Pedestrain_Trousers_Skirt_   2    //裙子 v5.5新增

// age：年龄段
#define Pedestrain_Child_            1    //儿童
#define Pedestrain_Adult_            2    //成人
#define Pedestrain_Older_            3    //老人
// hairColor：头发颜色
#define Pedestrain_Hair_Black_       1    //黑色
#define Pedestrain_Hair_White_       2    //白色
#define Pedestrain_Hair_Yellow_      3    //黄色
#define Pedestrain_Hair_Red_         4    //红色
// hairType：头发长度
#define Pedestrain_Hair_Short_       1    //短发
#define Pedestrain_Hair_Bald_        2    //光头
#define Pedestrain_Hair_Long_        3    //长发
// hairStyle: 
#define Pedestrain_Hair_Shawl_       1    //披肩 v5.5新增
#define Pedestrain_Hair_Ponytail_    2    //马尾 v5.5新增
#define Pedestrain_Hair_Upstyle_     3    //盘发 v5.5新增
// glassType：
#define Pedestrain_Glass_Nomal_      1    //普通眼镜 v5.5新增
#define Pedestrain_Glass_Dark_       2    //墨镜 v5.5新增

//车辆属性识别定义
//(1)vehicleType：车辆类型定义
#define Vehicle_Type_SALOON_		 1	  //小汽车
#define Vehicle_Type_VAN_			 2	  //面包车
#define Vehicle_Type_FREIGHT_		 3    //货车
#define Vehicle_Type_PASSENGER_	     4    //客车
#define Vehicle_Type_SUV_	         5    //SUV
#define Vehicle_Type_FREIGHT_BIG_	 6    //大货车
#define Vehicle_Type_PASSENGER_BIG_  7    //大客车
//#define Vehicle_Type_NO_STD_         8    //非标车
#define Vehicle_Type_FREIGHT_SML_	 9    //小货车 v4.5新增
#define Vehicle_Type_Pickup_        10    //皮卡   v4.5新增
#define Vehicle_Type_MPV_           11    //MPV    v6.0新增
#define Vehicle_Type_OFF_LOAD_      12    //越野   v6.5新增
//(1)vehicleTypeSpecial：车辆特殊车型定义
#define Vehicle_Type_Normal_		 0 	  //普通车型
#define Vehicle_Type_Dangerous_		 1	  //危险品运输车
#define Vehicle_Type_TAXI_		     2	  //出租车
#define Vehicle_Type_SchoolBus_      3    //校车
#define Vehicle_Type_PublicBus_      4    //公交车
#define Vehicle_Type_DumpTruck_      5    //泥头车
#define Vehicle_Type_MixerTruck_     6    //搅拌车
#define Vehicle_Type_GarbageTruck_   7    //垃圾运输车
#define Vehicle_Type_VanTruck_       8    //厢式货车
#define Vehicle_Type_PlateTruck_     9    //板式运输车
#define Vehicle_Type_TankTruck_     10    //油气罐车
#define Vehicle_Type_Trailer_       11    //拖车
#define Vehicle_Type_CanvasTruck_   12    //厢式货车(帆布)
#define Vehicle_Type_Ambulance_     13    //救护车
#define Vehicle_Type_Sprinkler_     14    //洒水车
//v5.0将车辆颜色修改成和非标车、衣服颜色映射表保持一致 (基线版本)
#define Vehicle_Color_Black_         1    //黑色
#define Vehicle_Color_Blue_          2    //蓝色
#define Vehicle_Color_Brown_         3    //棕色
#define Vehicle_Color_Green_         4    //绿色
#define Vehicle_Color_Grey_          5    //灰色
#define Vehicle_Color_Orange_        6    //橙色
#define Vehicle_Color_Pink_          7    //粉色
#define Vehicle_Color_Purple_        8    //紫色
#define Vehicle_Color_Red_           9    //红色
#define Vehicle_Color_White_        10    //白色
#define Vehicle_Color_Yellow_       11    //黄色
//(3) plateColor：车牌颜色定义
#define Plate_Color_BLUE_            1  //蓝色
#define Plate_Color_YELLOW_          2  //黄色
#define Plate_Color_WHITE_           3  //白色
#define Plate_Color_BLACK_           4  //黑色
#define Plate_Color_GREEN_           5  //绿色（新能源）
#define Plate_Color_RED_	         6  //红色（国外车牌）
#define Plate_Color_GRAY_	         7  //灰色（国外车牌）
#define Plate_Color_PURPLE_	         8  //紫色（国外车牌）
#define Plate_Color_YELLOW_GREEN_    9  //黄绿色（新能源）
//（4）plateType：车牌类型定义
#define Plate_Type_BLUE_             1   //蓝牌小汽车
#define Plate_Type_BLACK_            2   //单排黑牌
#define Plate_Type_YELLOW_           3   //单排黄牌
#define Plate_Type_YELLOW2_          4   //双排黄牌
#define Plate_Type_POLICE_           5   //警车车牌
#define Plate_Type_ARMPOL_           6   //单排武警车牌
#define Plate_Type_ARMPOL2_          7   //双排武警车牌
#define Plate_Type_ARMY_             8   //单排军车牌
#define Plate_Type_ARMY2_            9   //双排军车牌
#define Plate_Type_EMBASSY_         10   //使馆车牌
#define Plate_Type_HONGKONG_        11   //香港车牌
#define Plate_Type_TRACTOR_         12   //农用车牌
#define Plate_Type_MACAU_           13   //澳门车牌
#define Plate_Type_LINGGUAN_        16   //领馆汽车
#define Plate_Type_CIVIL_           17   //民航车牌
#define Plate_Type_BLACK2_          18   //双排黑牌
#define Plate_Type_GUACHE_          27   //挂车
#define Plate_Type_COACH_	        28   //教练汽车
#define Plate_Type_NEW_	            30   //新能源车牌
#define Plate_Type_TEMP_            31   //v6.5新增：临时车牌
#define Plate_Type_NO_	            32   //v4.0新增：无车牌
#define Plate_Type_DEFACE_	        33   //v4.5新增：污损车牌
#define Plate_Type_SHIELD_	        34   //v4.5新增：遮挡车牌
#define Plate_Type_ENGLISH_         35   //v4.5新增：国外车牌
//////////////////////////////////////////////////////////
//vehicle window相关
//annualShape 年检标的排列形状
#define Vehicle_AnnualShape_Block_         1  //v6.5新增：块状分布
#define Vehicle_AnnualShape_Widthwise_     2  //v6.5新增：横向分布
#define Vehicle_AnnualShape_Longitudinal_  3  //v6.5新增：纵向分布
//decorationType 摆件类型
#define Vehicle_DcorationType_Statue_      1  //v6.6新增：塑像
#define Vehicle_DcorationType_Doll_        2  //v6.6新增：布偶
#define Vehicle_DcorationType_Bottle_      3  //v6.6新增：水瓶
#define Vehicle_DcorationType_Deodorizer_  4  //v6.6新增：清新剂
#define Vehicle_DcorationType_Flag_        5  //v6.6新增：旗帜

// 非标车属性定义(与行人相似标签的定义一致)
// driverSex：性别
#define NoStdVehiclDriver_Female_           1    //女性
#define NoStdVehiclDriver_Male_             2    //男性
// noStdVehicleColor：非标车颜色
#define NoStdVehiclColor_Black_       1    //黑色
#define NoStdVehiclColor_Blue_        2    //蓝色
#define NoStdVehiclColor_Brown_       3    //棕色
#define NoStdVehiclColor_Green_       4    //绿色
#define NoStdVehiclColor_Grey_        5    //灰色
#define NoStdVehiclColor_Orange_      6    //橙色
#define NoStdVehiclColor_Pink_        7    //粉色
#define NoStdVehiclColor_Purple_      8    //紫色
#define NoStdVehiclColor_Red_         9    //红色
#define NoStdVehiclColor_White_      10    //白色
#define NoStdVehiclColor_Yellow_     11    //黄色
// driverCoatColor：上衣子颜色
#define NoStdVehiclDriver_Clothes_Black_    1    //黑色
#define NoStdVehiclDriver_Clothes_Blue_     2    //蓝色
#define NoStdVehiclDriver_Clothes_Brown_    3    //棕色
#define NoStdVehiclDriver_Clothes_Green_    4    //绿色
#define NoStdVehiclDriver_Clothes_Grey_     5    //灰色
#define NoStdVehiclDriver_Clothes_Orange_   6    //橙色
#define NoStdVehiclDriver_Clothes_Pink_     7    //粉色
#define NoStdVehiclDriver_Clothes_Purple_   8    //紫色
#define NoStdVehiclDriver_Clothes_Red_      9    //红色
#define NoStdVehiclDriver_Clothes_White_   10    //白色
#define NoStdVehiclDriver_Clothes_Yellow_  11    //黄色
// driverCoatType：上衣长短
#define NoStdVehiclDriver_Clothes_Short_    1    //短袖短裤
#define NoStdVehiclDriver_Clothes_Long_     2    //长袖长裤
// driverCoatText：衣服纹理
#define NoStdVehiclDriver_Clothes_Stripes_  1    //条纹 v4.5新增
#define NoStdVehiclDriver_Clothes_Lattice_  2    //格子 v4.5新增
// driverAge：年龄段
#define NoStdVehiclDriver_Child_            1    //儿童
#define NoStdVehiclDriver_Adult_            2    //成人
#define NoStdVehiclDriver_Older_            3    //老人
// dirverHairColor：头发颜色
#define NoStdVehiclDriver_Hair_Black_       1    //黑色
#define NoStdVehiclDriver_Hair_White_       2    //白色
#define NoStdVehiclDriver_Hair_Yellow_      3    //黄色
#define NoStdVehiclDriver_Hair_Red_         4    //红色
// dirverHairType：头发长度
#define NoStdVehiclDriver_Hair_Short_       1    //短发
#define NoStdVehiclDriver_Hair_Bald_        2    //光头
#define NoStdVehiclDriver_Hair_Long_        3    //长发
// hairStyle: 
#define NoStdVehiclDriver_Hair_Shawl_       1    //披肩 v5.5新增
#define NoStdVehiclDriver_Hair_Ponytail_    2    //马尾 v5.5新增
#define NoStdVehiclDriver_Hair_Upstyle_     3    //盘发 v5.5新增
// DeriverGlassType：
#define NoStdVehiclDriver_Glass_Nomal_      1    //普通眼镜 v5.5新增
#define NoStdVehiclDriver_Glass_Dark_       2    //墨镜 v5.5新增

//noStdVehicleType：非标车属性识别定义
#define NoStdVehicle_BatteryBike_           1    //电动自行车
#define NoStdVehicle_BatteryMotor_          2    //电动摩托车
#define NoStdVehicle_Bike_                  3    //自行车
#define NoStdVehicle_Motor_                 4    //摩托车
#define NoStdVehicle_MotorLight_            5    //轻型摩托车
#define NoStdVehicle_Tricycle_              6    //三轮车
//driverTypeSpecial
#define NoStdVehiclDriver_SF_               1    //顺丰 v4.2新增
#define NoStdVehiclDriver_Cavalry_          2    //交警铁骑 v5.5新增

//TricycleType
#define NoStdVehicl_Tricycle_Hopper_        1    //斗式三轮车 v5.5新增
#define NoStdVehicl_Tricycle_Shed_          2    //棚式三轮车 v5.5新增
#define NoStdVehicl_Tricycle_Box_           3    //厢式三轮车 v5.5新增
//////////////////////////////////////////////////////////

//以图搜图排序相关参数
#define  HZ_MAX_DIM_STRING_     64
#define  HZ_MAX_LOCAL_NUM_       6
#define  Retrival_Threshold_   0.5f         //默认的过滤阈值
#define  Retrival_Def_Near_    64           //默认值结果数量
#define  Retrival_Max_Near_    1024         //最大输出的结果数量
#define  Retrival_Max_Batch_  (1024*1024)   //最大batch数量lM
// 定长64字节
typedef struct hz_objectRetrivalParameter_
{
	float   Threshold;       //过滤阈值，>=0.5f
	int     nNear;           //最多输出前N个，默认值64
	// 保留空间
	char  reserved[56];
}hz_objectRetrivalParameter_;


////////////////////////////////////////////////////////////////////////////////////////////
//后回滚+前回滚定义(V4.1名字换了，对应值不变)
#define Data_Negative_                      0   //废片
#define Data_Postive_                       1   //正片
#define Data_Exception_                     2   //异常
//后回滚+前回滚返回废片原因
#define Return_Postive_                     0   // 正片
#define Return_Negative_                    1   // 废片
#define Return_ObjectNoPlate_               2   // 未悬挂车牌
#define Return_PlateTrajIncomp_             3   // 车牌轨迹不完整
#define Return_PlateNoClear_                4   // 车牌不清晰
#define Return_PlateError_                  5   // 车牌识别错误
#define Return_SpecialVehicle_              6   // 特殊车辆
#define Return_TruckRule_                   7   // 不满足大货车限行处罚规则
#define Return_RoadRule_                    8   // 不满足不按道行驶处罚规则
#define Return_ForeignPlate_                9   // 不满足限外处罚规则
#define Return_HaveSaftBelt0_              10   // 不满足主驾驶安全带处罚规则
#define Return_HaveSaftBelt1_              11   // 不满足副驾驶安全带处罚规则
#define Return_NoHaveCall0_                12   // 不满足主驾驶打电话处罚规则
#define Return_NoHaveBaby1_                13   // 不满足副驾驶抱小孩处罚规则
#define Return_NoHaveSmoke0_               14   // 不满足主驾驶抽烟处罚规则
#define Return_LineRule_                   15   //  不满足禁止标线规则
//v4.5新增
#define Return_CrossWalkRule_              16   // 不满足人行道停车让行处罚规则
#define Return_SpeedingRule_               17   // 不满足超速处罚规则
#define Return_LaneGuide_                  18   // 不满足不按车道导向处罚规则
#define Return_RunRedLights_               19   // 不满足闯红灯处罚规则
#define Return_IntersectionParking_        20   // 不满足路口停车处罚规则
//v5.5新增
#define Return_Retrograde_                 21   // 不满足逆行处罚规则
#define Return_YellowGridIllegalParking_   22   // 不满足黄网格违章停车规则
#define Return_IllegalParing_              23   // 不满足违章停车规则
//废片子原因
//v5.0新增
#define subReturn_Ambulance_                  33   // 救护车辆不采集
#define subReturn_Police_                     34   // 警车车辆不采集
#define subReturn_Army_                       35   // 军车车辆不采集
#define subReturn_Trailer_                    36   // 救援车辆（拖车）不采集
#define subReturn_Tractor_                    37   // 农用车辆不采集
#define subReturn_Sprinkler_                  38   // 洒水车辆不采集
#define subReturn_ShiLing_                    39   // 使领馆车辆不采集
//v5.5新增
#define subReturn_Missing_image               40   // 图片采集不全
#define subReturn_StopLineNotClear            41   // 地面停止线不清晰
#define subReturn_LaneNotClear                42   // 地面禁止标线不清晰
#define subReturn_FrontWheelPassedStopLine    43   // 车辆前轮已过停止线（图1）
#define subReturn_RearWheelNotPassedStopLine  44   // 车辆后轮未过停止线（图3）
//禁止标线
#define subReturn_SinglesidedPressureLine     45   // 车辆单侧压禁止标线
#define subReturn_NoPressureLine              46   // 车辆未压禁止标线
//礼让行人
#define subReturn_NotPedestrian               47   // 行人未在斑马线上
//闯红灯
#define subReturn_NotAllRedLights             48   //信号灯状态异常
//不按导向箭头
#define subReturn_ArrorNotClear               49   //地面导向标志不清晰


//////////////////////////////////////////////
//废片回滚（后回滚）功能选择(V4.1名字换了，对应值不变)
#define RollType_ForeignPlate_			    1    // 外地车
#define RollType_PlateNoExist_				2    // 无车牌
#define RollType_PlateNoClear_		        3    // 车牌汉字模糊
#define RollType_PlateError_		        4    // 车牌识别错误
#define RollType_TruckRule_	                5    // 大货车限行
#define RollType_RoadRule_		            6    // 不按道行驶
//废片回滚（后回滚）参数结构
typedef struct
{
	int  nRecycleType;							 // 后回滚功能选择
	char pProvince[8];							 // 默认地区， 如“粤B”
	int  nMatchPattern;							 // 车牌匹配模式（0精确匹配，1模糊匹配）
	int  nMatchNumber;							 // 模糊匹配字符数（>=4）
	char pInfoPlateNames[16];                    // 抓拍车牌号码
	int  nInfoLane;                              // 车道号
	char reserved[160];
}hz_InputParameter;


//////////////////////////////////////////////
//图片预审（前回滚）功能选择（19个判断规则,任意叠加）
#define PretrialType_ObjectNoPlate_                      1  // 未悬挂车牌
#define PretrialType_PlateNoClear_                       2  // 车牌不清晰
#define PretrialType_PlateTrajIncomp_                    4  // 车牌轨迹不完整(图片采集不全)
#define PretrialType_PlateError_                         8  // 车牌识别错误
//#define PretrialType_SpecialVehicle_                  16  // 特殊车型（弃用：拆分了多个类别）
#define PretrialType_TruckRule_                         32  // 大货车限行处罚规则
#define PretrialType_RoadRule_                          64  // 不按道行驶处罚规则
#define PretrialType_ForeignPlate_                     128  // 限外处罚规则
#define PretrialType_HaveSaftBelt0_                    256  // 主驾安全带处罚规则
#define PretrialType_HaveSaftBelt1_                    512  // 副驾安全带处罚规则
#define PretrialType_NoHaveCall0_                     1024  // 主驾打电话处罚规则
#define PretrialType_NoHaveBaby1_                     2048  // 副驾抱小孩处罚规则
#define PretrialType_NoHaveSmoke0_                    4096  // 主驾抽烟处罚规则
#define PretrialType_LineRule_                        8192  // 禁止标线规则
//v4.5新增
#define PretrialType_CrossWalkRule_                  16384  // 人行道停车让行规则
#define PretrialType_SpeedingRule_                   32768  // 超速规则
#define PretrialType_LaneGuide_                      65536  // 车道导向规则
#define PretrialType_RunRedLights_                  131072  // 闯红灯规则
#define PretrialType_IntersectionParking_           262144  // 路口停车规则
//v5.5新增
#define PretrialType_Retrograde_                    524288  // 逆行规则
#define PretrialType_YellowGridIllegalParking_     1048576  // 黄网格违章停车规则
#define PretrialType_IllegalParing_                2097152  // 违章停车规则（禁止停车标志）

//20190326特殊车辆细分过滤类型(任意叠加）
#define PretrialType_Ambulance_                   1  // 救护车辆不采集规则
#define PretrialType_Police_                      2  // 警车车辆不采集规则
#define PretrialType_Army_                        4  // 军车车辆不采集规则
#define PretrialType_Trailer_                     8  // 救援车（拖车）车辆不采集规则
#define PretrialType_Tractor_                    16  // 农用车辆不采集规则
#define PretrialType_Sprinkler_                  32  // 洒水车辆不采集规则
#define PretrialType_ShiLing_                    64  // 使领馆车辆不采集规则

//图片预审（前回滚）参数结构
//hz_pretrialParameter
typedef struct
{
	int   nPretrialType;					     // 前回滚功能选择
	char  pProvince[8];							 // 默认地区， 如“粤B”
	char  pInfoPlateNames[16];                   // 读取到的车牌信息
	int   nInfoLane;                             // 车道号
	int   nPretrialType_Special;                 // 特殊车辆(具体的细分类型)   20190326增加
	char  reserved[220];
}hz_pretrialParameter;
////////////////////////////////////////////////////////////////////////////////////////////



#ifndef _WIN64
#define __declspec(dllexport)  __attribute__((visibility("default")))
#endif

#endif // !hz_objectTypedef_
