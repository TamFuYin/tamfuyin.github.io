---
layout: default
title: Tam Fu Yin's Blog
---

这是我的个人博客主页。主要发布算法竞赛内容。


<button id="uploadBtn">上传博客</button>

<script>
document.getElementById("uploadBtn").onclick = async () => {
  const res = await fetch("https://github-pages-worker.tamfuyin.workers.dev/", {
    method: "POST",
    headers: { "Content-Type": "application/json" },
    body: JSON.stringify({ message: "Update from button" })
  });
  const text = await res.text();
  alert(text);
};
</script>




{% for post in site.blogs %}
- [{{ post.title }}]({{ post.url }})
{% endfor %}