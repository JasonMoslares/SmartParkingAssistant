import React, { useEffect, useState } from 'react'
import axios from 'axios'
import { Link } from 'react-router-dom'

function Home(){
    const [data, setData] = useState([])

    useEffect(()=> {
        const fetchData = () => {
            axios.get('http://localhost:3001/')
            .then(res => setData(res.data))
            .catch(err => console.log(err));
        };

        fetchData();

        const interval = setInterval(fetchData, 2000);

        return () => clearInterval(interval);
    }, [])

    const handleDelete = (id) => {
        axios.delete('http://localhost:3001/delete/'+id)
        .then(res => {
            window.location.reload();
        }).catch(err => console.log(err));
    }

    return (
    <div className='d-flex vh-100 bg-primary justify-content-center align-items-center'>
        <div className='w-50 bg-white rounded p-3'>
            <h2>Parking List</h2>
            <div className='d-flex justify-content-end'> 
                <Link to="/create" className='btn btn-success'>Create +</Link>
            </div>
            <table className='table'>
                <thead>
                    <tr>
                        <th>ID</th>
                        <th>Parking Name</th>
                        <th>Status</th>
                        <th>Action</th>
                    </tr>
                </thead>
                <tbody>
                    {data.map((photosensor, index) => {
                        return <tr key={index}>
                            <td>{photosensor.id}</td>
                            <td>{photosensor.parking_name}</td>
                            <td>{photosensor.status}</td>
                            <td>
                                <Link to={`/edit/${photosensor.id}`} className='btn btn-sm btn-primary mx-2'>Edit</Link>
                                <button onClick={ () => handleDelete(photosensor.id)} className='btn btn-sm btn-danger'>Delete</button>
                            </td>
                        </tr>
                    })}
                </tbody>
            </table>
        </div>
    </div>
  )
}

export default Home;
