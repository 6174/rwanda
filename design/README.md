## 问题

1. 原生的布局也有layout过程，通过webkit来排版然后再让view来layout是否会过程重复导致性能问题？ 
应该怎样避免原生系统的layout过程，而只需要render过程

2. 对于scroll的情况应该怎样处理？ 使用原生的scrollView？ 
那在html中如果设置了overflow:scroll的都设置为 scrollView吗？ 还是可以自动重一般的view转化为scrollView， 还是自定义一个基础的view，有scroll特性，所有的view都继承自它。 

3. 用户有自定义组件的情况， 如何在html使用自定义view? 添加component属性和platform属性？ 

4. template的情况， 在ui设计过程中又很多需要重复利用的模板，如何设计并利用这些模板？ 

5. 应该怎样使用， 像一个webview一样使用？ 还是在activity层级使用？






