qsNo = 0;
exam = [{
  qs: '',
  multi: false,
  req: false,
  opt: [],
  input: '',
  selected: null,
  solution: []
}];

function setQs() {
  if ($('#qs').val() != '')
    exam[qsNo].qs = $('#qs').val();

  for (i = 0; i < 4; i++) {
    var opt = $('.options').eq(i).val();
    if (opt != '' && exam[qsNo].opt.indexOf(opt) == -1)
      exam[qsNo].opt.push($('.options').eq(i).val());
  }
  console.log(exam[qsNo]);
}

function loadQs(m) {
  setQs();
  /* if (qsNo < exam.length - 1 && m == 1) {
    if (exam[qsNo].qs != null && exam[qsNo].qs != '' && exam[qsNo].opt.length > 1) {
      exam.push({
        qs: '',
        multi: false,
        req: false,
        opt: [],
        input: '',
        selected: null,
        solution: []
      })
    }
    else
      return;
  } else if (m == 0 || qsNo > 0 && m == -1)
    qsNo = qsNo + m; */
  if (m == 0 || qsNo > 0 && m == -1 || qsNo < exam.length - 1 && m == 1)
    qsNo = qsNo + m;
  else
    return;
  $('#qs').val(exam[qsNo].qs);
  for (i = 0; i < 4; i++) {
    $('.options').eq(i).val(exam[qsNo].opt[i]);
  }
  loadOptions();
}

function loadOptions() {
  $('.options').removeClass('selected');
  var sol = exam[qsNo].solution;
  if (sol != null) {
    for (i = 0; i < sol.length; i++)
      $('.options').eq(exam[qsNo].opt.indexOf(sol[i])).addClass('selected');
  }
}

function selectOption(option) {
  var opt = exam[qsNo].solution;
  var val = $('.options').eq(option).val();
  if (opt.indexOf(val) != -1)
    opt = opt.filter((o) => o != val && o != '')
  else
    opt.push(val);

  exam[qsNo].multi = opt.length > 1;
  exam[qsNo].solution = opt;
  console.log(opt);
  $('.options').eq(option).toggleClass('selected')
}
