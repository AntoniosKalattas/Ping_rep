console.log("ok");

var ip;

function update_status(){
  ip=document.getElementById("ip").value;
    var today = new Date();
    var date = today.getDate()+'-'+(today.getMonth()+1)+'-'+today.getFullYear();
    var time = today.getHours()+":" + today.getMinutes();
    var dateTime = time+" "+date;
    console.log(ip);
    console.log('I am going to update the chat room')
    const li = document.createElement('li');
    li.innerHTML = `<div class="entete">
      <span class="status blue"></span>
    </div>
    <div class="message">
      fgdhdfgdfgdfgdf
    </div>`;
    document.querySelector('.status').appendChild(li);
  }