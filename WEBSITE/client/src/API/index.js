import axios from 'axios'

export const fetchData = (setVarName) => {
    axios.get('http://localhost:3001/read')
    .then(res => {console.log(res); setVarName(res.data)})
    .catch(err => console.log(err))
}

export const handleCreate = (e, varName, nav) => {
    e.preventDefault();
    axios.post('http://localhost:3001/create/lot', varName)
    .then(res => {console.log(res); nav('/')})
    .catch(err => console.log(err))
}

export const handleRead = (id, setVarName) => {
    axios.get('http://localhost:3001/read/'+id)
    .then(res => {console.log(res); setVarName({parking_name: res.data[0].parking_name})})
    .catch(err => console.log(err))
}

export const handleUpdate = (e, id, values, nav) => {
    e.preventDefault();
    axios.put('http://localhost:3001/update/'+id, values)
    .then(res => {console.log(res); nav('/')})
    .catch(err => console.log(err));
}

export const handleDelete = (id) => {
    axios.delete('http://localhost:3001/delete/'+id)
    .then(res => {window.location.reload();})
    .catch(err => console.log(err));
}
