(()=>{var o={fallback:"https://liushuojiang.github.io/blogs/",homes:{en:"https://liushuojiang.github.io/blogs/","zh-hans":"https://liushuojiang.github.io/blogs/zh-hans/"}};(()=>{let i=navigator.language||navigator.userLanguage;if(i in o.homes){window.location.href=o.homes[i];return}let n=i.split("-");for(let a in o.homes)if(a.indexOf(n[0])===0){window.location.href=o.homes[a];return}window.location.href=o.fallback})();})();