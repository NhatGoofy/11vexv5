code sử dung của GitHub
đầu tiên trong file phải sử dung lệnh này TRƯỚC:
1.**$env:Path = [Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [Environment]::GetEnvironmentVariable("Path", "User")

where.exe git**

git --version
***các lệnh chỉ việc them vào:**
**git config --global user.name "Nhat Hua"
git config --global user.email "emailcuaban@gmail.com"**
// có thể đổi user name và email của mình để dễ nhận biết file nào là file mình thôi
bước 2: thực hiện lệnh giúp git nhận diện file:
**2.git init**

(1); từ working space -> stage area = **git add.** ( lưu ý file sửa sẽ đại diện là M, file mới đại diện là A)
(2); từ stage space -> git local = **git commit-m" đặt tên"**
(3); từ git local -> working space = **git checkout+ tên file**

cách để đẩy file git local lên file GitHub trên mạng
 **git push**
cách để người cộng tác còn lại có thể kết nối tới file GitHub:
**git clone** hoặc  **git remote add origin [URL]**
1 phần lưu ý: để người cộng tác viên còn lại lấy file trên web thì cần sử dung lệnh:
**git pull**
LƯU Ý:nếu mà đã thực hiện những bước trên mà báo lỗi thì hãy sử dụng chatgpt để khắc phục nha!
