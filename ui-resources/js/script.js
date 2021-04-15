function myFunction() {
    // var id = document.getElementById("id3");
    alert("myFunction is Connected");
}

function showArea(event) {
    var width = parseFloat(event.target.getAttributeNS(null, "width"));
    var height = parseFloat(event.target.getAttributeNS(null, "height"));
    alert("Area of the rectangle is: " + width + "x" + height);

    console.log(width, height);
}

function waitForSVG() {
    var svgObj = document.getElementById("svgObj");
    var svgDoc;
    svgObj.addEventListener("load", function () {
        svgDoc = svgObj.contentDocument;
    }, false);
}

function setClickEvents() {
    var svgObj = document.getElementById("svgObj");

    var svgDoc = svgObj.contentDocument;
    var svgItem = svgDoc.getElementById("r1");
    svgItem.addEventListener("click", showArea);
}