qsNo=0;
exam=[
  {
    qs:'From where do you get printouts',
    multi:false,
    req:true,
    opt:['Home', "Parent's workplace", "Shop",'other'],
    input:'',
    selected:null,
    solution:null
  },
  {
    qs:'Have you ever needed a printout late at night and not been able to get it?',
    multi:false,
    req:true,
    opt:['Very often', 'Sometimes', 'Rarely', 'Never'],
    input:'',
    selected:null,
    solution:null
  }
];

function loadQs(m) {
//to store the other input
  if(exam[qsNo].opt[exam[qsNo].selected]==='other'){
    exam[qsNo].input=$('#other').value;
    console.log($('#other').value);
  }

  if (m == 0 || qsNo > 0 && m == -1 || qsNo < exam.length-1 && m == 1)
    qsNo = qsNo + m;
  else
    return;
  $('#qs').text(exam[qsNo].qs);
  loadOptions();
}

function loadOptions(){
  for (i = 0; i < 4; i++) {
    if (i < exam[qsNo].opt.length){
//if other is a given option take user text input
      if(exam[qsNo].opt[i]==='other'){
        $('.options').eq(i).html("Other <input type='text' name='other' id='other' class=options value='why'>");//defective
        //if(exam[qsNo].input.length>0)
	  //$('#other').value=exam[qsNo].input;
      }else{
        $('.options').eq(i).text(exam[qsNo].opt[i]);
        $('.options').eq(i).show();
      }
    }else
      $('.options').eq(i).hide();
  }
  $('.options').removeClass('selected');
  if(exam[qsNo].selected!=null)
    $('.options').eq(exam[qsNo].selected).addClass('selected');
}

function selectOption(option) {
  if (!exam[qsNo].multi)
    $(".options").removeClass("selected");
  $(".options").eq(option).toggleClass('selected');
  exam[qsNo].selected = option;
}
