## 问题

1. 原生的布局也有layout过程，通过webkit来排版然后再让view来layout是否会过程重复导致性能问题？ 
应该怎样避免原生系统的layout过程，而只需要render过程

2. 对于scroll的情况应该怎样处理？ 使用原生的scrollView？ 
那在html中如果设置了overflow:scroll的都设置为 scrollView吗？ 还是可以自动重一般的view转化为scrollView， 还是自定义一个基础的view，有scroll特性，所有的view都继承自它。 

3. 用户有自定义组件的情况， 如何在html使用自定义view? 添加component属性和platform属性？ 

4. template的情况， 在ui设计过程中又很多需要重复利用的模板，如何设计并利用这些模板？ 

5. 应该怎样使用， 像一个webview一样使用？ 还是在activity层级使用？



## 解决方

1. 对于android 里边的view，绘制过程为
 ```
    * measure (测量视图的大小，final方法，无法在子类中重写) 
    * onmeasure 
    * layout (确定视图的位置)
    * onlayout (抽象方法，viewGroup子类必须实现) 
    * draw (..)
    * ondraw (..) 
 ```
 所以，无法避免android里边的view的measure，除非只用一个view，但鉴于对于绝对定位的viewGroup，这样带来的性能影响应该不大， 当然需要数据支持 ， 所以现在的方案还是继承ViewGroup或View

2. android里边每个view都由scrollbar的渲染逻辑，只是没有绘制出来， 所以这个应该不是问题

3. r-view 指定组件名称，r-namespace自定路径，r-platform指定平台

4. 学习android的inflate，每个文件都是模板，或者说一个组件的view定义。 在这个基础上，其他组件可以内嵌相互引用，通过template 标签引用其他模板。    

5. view层级，按照组件的方式调用，组件可以是activity层级的组件，也可以是label层级的组件 




