# 一.账户管理子系统和商品管理子系统（单机版）
1) 用户注册&登录：支持新用户注册平台账号，已注册用户用平台账号登录平
台，要求已注册用户的信息长久保留。
2) 修改账户密码：支持登录后对用户账号的密码修改。
3) 余额管理：支持用户账号中余额的查询、充值、消费等。
4) 添加商品：支持商家添加新商品，要求已添加的商品信息长久保留。
5) 展示平台商品信息：支持针对不同类型用户、无论登录与否均展示平台商品
信息。
6) 搜索平台商品信息：支持依据某种条件（比如：名称）对平台商品进行筛选，
并展示筛选结果。
7) 商品信息管理：支持商家对其商品的信息进行管理，包括但不限于价格管理、
剩余量管理等
主要要求如下：

⚫ 要求 1：账户至少需要账号名、密码、账户余额、账户类型（商家/消费者）
等内容。

⚫ 要求 2：请把所有的用户账户信息写入文件（要求使用文件存储各类信息，
以练习对文件的操作和流的输入输出），注册新账户的时候，要求注册的账
户名不能已经存在于文件中，即账户名唯一。

⚫ 要求 3：请至少设计一层继承体系（用户基类-用户子类）。设计一个用户基
类，然后让商家类和消费者类等用户子类继承它，具体的用户是用户子类
的实例对象（<<张三 >> 是消费者类的实例对象）。用户基类为抽象类，
不能实例化，请至少具有一个纯虚函数 getUserType()用于指示用户类别。

⚫ 要求 4：电商平台上至少有三类商品：如食物、服装、图书等，每类商品
中至少有三个具体的商品（如图书中可以有《C++ Primer》、《Effertive C++》
等），每个具体的商品请至少包含商品描述、商品原价、商品剩余量等数据。
所有的商品信息需要存储在文件或数据库中，不能写在代码中。

⚫ 要求 5：请至少设计一层继承体系（商品基类-商品子类）。设计一个商品基
类，然后让图书类、电子商品类和服装类等商品子类继承它，具体的商品
是商品子类的实例对象（<<C++ Primer >> 是图书类的实例对象） 。商
品基类请至少具有一个虚函数 getPrice()用于计算具体商品的价格。

⚫ 要求 6：支持对同一品类下所有产品打折的活动。

⚫ 要求 7：支持一定的错误场景处理能力，例如读文件错误，输入数据不合
法等等。

# 二.交易管理子系统（单机版）
1) 购物车管理：支持消费者向购物车添加、删除指定数量的商品，也支持消费
者修改当前购物车商品的拟购买数量。
2) 订单生产：选择购物车的商品生成订单，计算并显示订单总金额。
3) 网上支付：消费者使用余额支付订单，支付成功后，消费者被扣除的余额应
转至商家余额中。

主要要求如下：

⚫ 要求 1：当订单生成后，处于未支付状态时，应将对应数量的商品冻结，不
能参与新订单的产生，避免商品被超额售卖。

⚫ 要求 2：支持一定的错误场景处理能力，如生成订单失败，支付失败等。

# 三.电商交易平台（网络版）
1) 用户登录：用户通过客户端以账号密码登录平台。
2) 展示平台商品信息：通过客户端展示平台商品信息。
3) 搜索平台商品信息：通过客户端依据商品名称对平台商品进行搜索筛选，并
展示筛选结果。
4) 购物车管理：通过客户端支持消费者向购物车添加、删除指定数量的商品。
5) 订单生产： 系统生成订单，通过客户端展示用户的订单信息。
6) 订单支付：用户通过客户端向系统提交订单支付的申请，并展示系统完成支
付的状态。
主要要求如下：

⚫ 要求 1：网络版需要实现的功能的要求与单机版要求一致。

⚫ 要求 2：要求采用传统 CS 结构而非 BS 结构，客户端与服务器系统之间使 用 socket 进行通信，不能使用 rpc 框架。

⚫ 要求 3：支持一定的错误场景处理能力。



程序设计要求

⚫ 如有必要的友元函数，要在实验报告和程序中说明每个友元函数的不可
替代性，为什么一定要用友元才能实现。

⚫ 自己编写的代码，除主函数和必要的友元函数外，不允许出现任何一个
非类成员函数。

⚫ 任何不改变对象状态（不改写自身对象数据成员值）的成员函数均需显
式标注 const。
