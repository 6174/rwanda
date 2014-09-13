#HTML 解析

## Flow
1. Loader 
2. tokenizer
3. tree builder 
4. DOM tree

**[html解析标准](http://www.whatwg.org/specs/web-apps/current-work/multipage/syntax.html#parsing)**

## Step one: Loader 

**需要加载的资源**  

1. `html文本`, `css`, `img`, `font` 
2. webkit主资源： `html文本` 
3. webcore/loader/cache 目录下面：
 ![资源类图](http://gtms04.alicdn.com/tps/i4/TB1DTdeGXXXXXcqaXXXc9Q93XXX-537-227.png)  
4. CachedResourceClient 用于监听资源加载状态信息
5. CachedResourceLoader 负责资源加载的策略


### Img加载过程

**HTML解析器解析到该`<img src="***"/>`时，会创建一个ImageLoader对象来加载它:** 

![](http://www.ituring.com.cn/download/01YUSolMEL3j)


### 缓冲机制

**WebKit利用MemoryCache和CachedResourceLoader来实现资源缓存机制，不同的HTML文档，不共享缓冲（需要优化的地方）**
![](http://www.ituring.com.cn/download/01YUSolUPczP)


## 渲染逻辑

1. `1:1`    Node/Element <-> RenderObject 
2. `many:1` RenderObject <-> styleRule
