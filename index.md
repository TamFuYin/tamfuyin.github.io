---
layout: default
title: Tam Fu Yin's Blog
---

这是我的个人博客主页。主要发布算法竞赛内容。

<button id="uploadBtn">📝 一键上传博客</button>

<script>
document.getElementById("uploadBtn").addEventListener("click", async () => {
  const token = "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"; // ⚠️ 不推荐放在网页中！仅测试用
  const owner = "tamfuyin";
  const repo = "tamfuyin.github.io";

  const response = await fetch(`https://api.github.com/repos/${owner}/${repo}/dispatches`, {
    method: "POST",
    headers: {
      "Accept": "application/vnd.github.v3+json",
      "Authorization": `token ${token}`,
    },
    body: JSON.stringify({
      event_type: "deploy_blog",
    }),
  });

  if (response.ok) {
    alert("✅ 已自动上传！");
  } else {
    alert("❌ 触发失败，请检查 token 或权限。");
  }
});
</script>


{% for post in site.blogs %}
- [{{ post.title }}]({{ post.url }})
{% endfor %}