---
layout: default
title: Tam Fu Yin's Blog
---

这是我的个人博客主页。主要发布算法竞赛内容。

<button id="uploadBtn">📝 一键上传博客</button>

<script>
document.getElementById("uploadBtn").addEventListener("click", async () => {
  const response = await fetch("https://github-pages-worker.tamfuyin.workers.dev/", {
    method: "POST"
  });

  if (response.ok) {
    alert("✅ 已触发自动上传！");
  } else {
    alert("❌ 触发失败，请检查 Worker 部署。");
  }
});
</script>



{% for post in site.blogs %}
- [{{ post.title }}]({{ post.url }})
{% endfor %}