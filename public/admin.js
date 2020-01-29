function findAlerts() {
    fetch('http://localhost:3000/getuserdetails')
        .then(
            function(response) {
                if (response.status !== 200) {
                    console.log('Looks like there was a problem. Status Code: ' +
                        response.status);
                    return;
                }

                response.json().then(function(data) {
                    var resultArray = JSON.stringify(data);
                    console.log(resultArray);

                    list_id++;
                    var a = list_id.toString();
                    x = 'list_item_' + a;
                    y = 'list_btn_' + a;
                    console.log('a= ' + a);


                    var node = document.createElement("LI");
                    node.classList.add("collection-item");
                    node.setAttribute("id", x);


                    node.innerHTML = trim_msg + "<span class=\"new badge\" data-badge-caption=\"Raise Ticket\" id=" + y + " onclick=\"raise_ticket(id)\"/>"
                    document.getElementById("abox").appendChild(node);

                });
            }
        )
}
